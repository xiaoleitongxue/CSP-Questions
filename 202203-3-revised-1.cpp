#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;
struct Node{
    int id;
    int cnt;
    int from;
    int node_seq;
    map<int, bool> book_applications;
    bool operator<(const Node &a) const
    {
        if (cnt != a.cnt)
            return cnt > a.cnt;
        else
            return id > a.id;
    }
};
vector<Node> partitions[1006];
int n, m, g;

priority_queue<Node> chose(int a, int na, int pa, int paa){
    vector<Node> c1;
    //选出指定分区内的结点
    if(na){
        for(int i = 0; i < partitions[na].size(); ++i){
            c1.push_back(partitions[na][i]);
        }
    }else{
        for(int i = 1; i <= m; ++i){
            for(int j = 0; j < partitions[i].size(); ++j){
                c1.push_back(partitions[i][j]);
                
            }
        }
    }
    //过滤结点亲和性
    vector<Node> c2;
    if(pa){
        set<int> qu;
        for(int i = 0; i < c1.size(); ++i){
            //得到pa所在的所有区
            //将c1中所有属于该区的节点并入
            if(c1[i].book_applications[pa]){
                qu.insert(c1[i].from);
            }
        }
        set<int> :: iterator it;
        for(it = qu.begin(); it != qu.end(); ++it){
            for(int i = 0; i < c1.size(); ++i){
                if(c1[i].from == *it){
                    c2.push_back(c1[i]);
                }
            }
        }
    }else{
        c2 = c1;
    }
    //过滤节点非亲和性
    vector<Node> c3;
    if(paa){
        for(int i = 0; i < c2.size(); ++i){
            if(!c2[i].book_applications[paa]){
                c3.push_back(c2[i]);
            }
        }
    }else{
        c3 = c2;
    }
    priority_queue<Node> final;
    for(int i = 0; i < c3.size(); ++i){
        final.push(c3[i]);
    }
    return final;

}

int ans(int tf, priority_queue<Node> &final, int a, int paa){
    while(tf && !final.empty()){
        Node node = final.top();
        final.pop();
        cout << node.id << ' ';
        partitions[node.from][node.node_seq].cnt++;
        partitions[node.from][node.node_seq].book_applications[a] = true;
        //如果反亲和不是自己，则该计算结点还可以再容纳应用a的其他任务。
        if(a != paa){
            node.cnt++;
            final.push(node);
        }
        tf--;
    }
    return tf;
}


int main(){
    cin >> n >> m;
    int pre_node_from = -1;
    int node_seq = -1;
    for(int i = 0; i < n; ++i){
        int node_from;
        cin >> node_from;
        Node node;
        node.id = i + 1;
        if(node_from != pre_node_from){
            node_seq = 0;
        }else{
            node_seq++;
        }
        pre_node_from = node_from;
        node.from = node_from;
        node.node_seq = node_seq;
        partitions[node_from].push_back(node);
    }
    cin >> g;
    int nums[1006][6] ={0};
    for(int i = 0; i < g; ++i){
        int f, a, na, pa, paa, paar;
        cin >> f >> a >> na >> pa >> paa >> paar;
        nums[i][0] = f;
        nums[i][1] = a;
        nums[i][2] = na;
        nums[i][3] = pa;
        nums[i][4] = paa;
        nums[i][5] = paar; 
    }
    int i = 0;
    while(g--){
        int f, a, na, pa, paa, paar;
        f= nums[i][0];
        a = nums[i][1];
        na = nums[i][2];
        pa = nums[i][3];
        paa = nums[i][4];
        paar = nums[i][5];
        ++i;
        priority_queue<Node> final = chose(a, na, pa, paa);
        int tf = ans(f, final, a, paa);
        //如果反亲和性并不是必须要满足，则重新筛选
        if(tf && !paar){
            final = chose(a, na, pa, 0);
            tf = ans(tf, final, a,  0);
        }
        while(tf--) cout << 0 << ' ';
        cout << endl;
    }
    return 0;
}

/*
10 4
1 1 1 1 1 2 2 2 2 2
6
2 1 4 1 2 1
6 1 1 0 1 1
1 2 2 0 0 0
6 1 2 0 2 1
5 2 2 0 1 0
11 3 0 1 3 0
*/