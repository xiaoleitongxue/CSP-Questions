//
// Created by lilei on 2022/3/25.
//
// score 70
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main(int, char**){
    int n, N;
    cin >> n >> N;
    vector<int> nums(n+1, 0);
    for(int i = 1; i < n + 1; ++i){
        cin >> nums[i];
    }
    int r = N/(n + 1);
    vector<int> f(N, 0);
    vector<int> g(N, 0);
    int j = 1;
    for(int i = 1; i < N;){
        if(j == n + 1){
            f[i] = n;
            ++i;
        }else if(i < nums[j]){
            f[i] = j - 1;
            ++i;
        }else if(i == nums[j]){
            f[i] = j;
            ++i;
        }else{
            ++j;
        }
    }
    for(int i = 0; i < N; ++i){
        g[i] = i / r;
    }
    vector<int> errors(N, 0);
    for(int i = 0; i < N; ++i){
        errors[i] = abs(g[i] - f[i]);
    }
    cout << accumulate(errors.begin(), errors.end(), 0);
}