//正确	100	171ms
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    /* data */
    int id;
    int cnt;
    int from;
    map<int, bool> book; // what application run in Node
    bool operator<(const Node &a) const
    {
        if (cnt != a.cnt)
            return cnt > a.cnt;
        else
            return id > a.id;
    }
} node[1006];
// what application run in each qu
map<int, bool> qu[1006];
int n, m, g;
/*
参数列表
a 应用程序id
na 该应用指定的可用区
pa 亲和性，其他某个应用的id，在同一区
paa 反亲和性，某个应用的id， 在不同的计算节点
paar 亲和性是否必须满足
*/
priority_queue<Node> chose(int &a, int &na, int &pa, int paa, int &paar)
{
    vector<Node> c1;
    // 选出区内可用节点
    if (na)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (node[i].from == na)
            {
                c1.push_back(node[i]);
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            c1.push_back(node[i]);
        }
    }
    //亲和性
    vector<Node> c2;
    if (pa)
    {
        for (int i = 0; i < c1.size(); ++i)
        {
            //指定区内的应用
            if (qu[c1[i].from][pa])
            {
                c2.push_back(c1[i]);
            }
        }
    }
    else
    {
        c2 = c1;
    }
    vector<Node> c3;
    if (paa)
    {
        for (int i = 0; i < c2.size(); ++i)
        {
            if (!c2[i].book[paa])
            {
                c3.push_back(c2[i]);
            }
        }
    }
    else
    {
        c3 = c2;
    }
    priority_queue<Node> final;
    for (int j = 0; j < c3.size(); j++)
        final.push(c3[j]);
    return final;
}

int ans(int tf, priority_queue<Node> &final, int &a, int paa)
{
    while (tf && !final.empty())
    {
        Node temp = final.top();
        final.pop();
        cout << temp.id << ' ';
        node[temp.id].cnt++;
        node[temp.id].book[a] = true;
        qu[temp.from][a] = true;
        //如果反亲和不是自己，则该节点可用
        if (a != paa)
        {
            temp.cnt++;
            final.push(temp);
        }
        tf--;
    }
    return tf;
}

int main()
{
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