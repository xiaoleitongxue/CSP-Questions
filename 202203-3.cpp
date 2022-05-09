#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node
{                        //存放计算节点的结构体
    int id;              //节点编号
    int cnt;             //节点运行的任务数
    int from;            //节点所在可用区的编号
    map<int, bool> book; //节点运行了什么任务
    bool operator<(const Node &a) const
    { //重载运算符，先比较cnt再比较id
        if (cnt != a.cnt)
            return cnt > a.cnt;
        else
            return id > a.id;
    }
} node[1006];

map<int, bool> qu[1006]; //每个可用区运行了什么任务
int n, m, g;

//过滤可用的节点入堆，最后返回该堆
//每次过滤都遍历一遍所有节点
priority_queue<Node> chose(int &a, int &na, int &pa, int paa, int &paar)
{
    //过滤节点亲和性
    vector<Node> c1;
    if (na)
    {
        for (int j = 1; j <= n; j++)
        {
            if (node[j].from == na)
                c1.push_back(node[j]);
        }
    }
    else
    {
        for (int j = 1; j <= n; j++)
            c1.push_back(node[j]);
    }
    //过滤任务亲和性
    vector<Node> c2;
    if (pa)
    {
        for (int j = 0; j < c1.size(); j++)
        {
            if (qu[c1[j].from][pa])
                c2.push_back(c1[j]);
        }
    }
    else
        c2 = c1;
    //过滤任务反亲和性
    vector<Node> c3;
    if (paa)
    {
        for (int j = 0; j < c2.size(); j++)
        {
            if (!c2[j].book[paa])
                c3.push_back(c2[j]);
        }
    }
    else
        c3 = c2;
    //把所有可用节点入堆排序
    priority_queue<Node> final;
    for (int j = 0; j < c3.size(); j++)
        final.push(c3[j]);
    // final中存着所有排好序的可用节点
    return final;
}

//打印答案并更新节点信息
int ans(int tf, priority_queue<Node> &final, int &a, int paa)
{
    while (tf && !final.empty())
    { //任务都分配完了或者可用节点没了都要结束循环
        Node temp = final.top();
        final.pop();
        cout << temp.id << ' ';
        //更新节点信息
        node[temp.id].cnt++;
        node[temp.id].book[a] = true;
        qu[temp.from][a] = true;
        //如果反亲和性是它自己，则这个节点不可用了。否则还要把这个节点入堆
        if (a != paa)
            temp.cnt++, final.push(temp);
        tf--;
    }
    return tf;
}

int main()
{
    // n节点的数目
    // m可用区的数目
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        node[i].id = i; //初始化节点id
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        node[i].from = temp;
    }
    cin >> g;
    while (g--)
    {
        int f, a, na, pa, paa, paar;
        cin >> f >> a >> na >> pa >> paa >> paar;
        priority_queue<Node> final = chose(a, na, pa, paa, paar);
        int tf = ans(f, final, a, paa);
        if (tf && !paar)
        { //如果任务没分配完并且反亲和性不是必须的，那么再过滤一次，再打印一次
            final = chose(a, na, pa, 0, paar);
            tf = ans(tf, final, a, 0);
        }
        while (tf--)
            cout << 0 << ' '; //剩下的是实在无法分配的任务，全输出0
        cout << endl;
    }
    system("pause");
    return 0;
}

/*
过滤步骤
1. 运行在特定的可用区内(筛选出特定节点集合c1)
2. [计算任务亲和性]必须和某个编号的应用的任务运行在同一个可用区内(筛选出特定节点集合c2)
3. [计算任务反亲和性]不能和某个编号的应用的任务运行在同一个计算节点上(筛选出特定节点集合c3)
4. 在还有节点剩余的情况下，看是否必须满足反亲和性，若不必，则再筛选一遍

综上所述，本题的关键就在于不断筛选出符合要求的节点
筛选的要素是
1. 通过应用编号查找任务所在的区(区内运行了什么应用)
2. 通过应用编号查找任务所在的计算节点(节点内运行了什么应用)
3. 一个应用对应多个任务，不同的任务在不同的计算节点上， 不同的计算节点可能属于不同的区
*/
