//
// Created by lilei on 2022/4/25.
// 分数100， 但用vector做占用内存较大，耗时较多
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> U(a, vector<int> (2));
    vector<vector<int>> V(b, vector<int> (2));
    for(int i = 0; i < a; ++i){
        cin >> U[i][0] >> U[i][1];
    }
    for(int i = 0; i < b; ++i){
        cin >> V[i][0] >> V[i][1];
    }
    long long sum = 0;
    int i = 0, j = 0;
    while(i < U.size() && j < V.size()){
        if(U[i][0] == V[j][0]){
            sum += U[i][1] * V[j][1];
            ++i;
            ++j;
        }else if(U[i][0] < V[j][0]){
            i++;
        }else{
            j++;
        }
    }
    cout << sum << endl;
    return 0;
}

/*
 解法二，用原生数组做，速度快，内存小
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int idx;
    int val;
}vec1[500005], vec2[500005];
int main()
{
    ios::sync_with_stdio(false);
    int n, a, b, p1 = 0, p2 = 0;
    long long ans = 0;
    cin >> n >> a >> b;
    for(int i = 0; i < a;i++)
        cin >> vec1[i].idx >> vec1[i].val;
    for(int i = 0; i < b; i++)
        cin >> vec2[i].idx >> vec2[i].val;
    while(p1 < a && p2 < b){
        if(vec1[p1].idx == vec2[p2].idx){
            ans += vec1[p1].val * vec2[p2].val;
            p1++;
            p2++;
        }
        else if(vec1[p1].idx < vec2[p2].idx)
            p1++;
        else
            p2++;
    }
    cout << ans;
    return 0;
}

*/
