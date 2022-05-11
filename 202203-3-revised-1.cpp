/**
 * 正确	100	156ms
 **/

/**
 * @file 202203-3-revised-1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 解题总结：这种题的特点是题目特别长，要仔细梳理题目的意思，理清条件，设出恰当的变量，结构体等
 */
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;
struct Node{
    int id;
    int cnt;
    int from;
    map<int, bool> book_applications;
    //运算符重载，希望node从小到大排列
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
    //过滤节点亲和性
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
        //find node index in vector
        int index = 0;
        for(index; index < partitions[node.from].size(); ++index){
            if(partitions[node.from][index].id == node.id){
                break;
            }
        }
        partitions[node.from][index].cnt++;
        partitions[node.from][index].book_applications[a] = true;
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
    //在输入数据时，题目并没有保证结点所在区是按非递减顺序依次输入的
    //这个坑卡了我很久
    for(int i = 0; i < n; ++i){
        int node_from;
        cin >> node_from;
        Node node;
        node.id = i + 1;
        node.from = node_from;
        partitions[node_from].push_back(node);
    }
    cin >> g;
    int nums[2000][6] ={0};
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