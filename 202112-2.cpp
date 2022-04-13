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
    int nums[n+1] = {0};
    for(int i = 1; i < n + 1; ++i){
        cin >> nums[i];
    }
    int f[N] ={0};
    int g[N] = {0};
    int err[N] = {0};
    int i = 0;
    int j = 0;
    while(i < N){
        cout << i << ' ' << j << endl;
        if(j < n + 1){
            if(i < nums[j]){
                f[i] = j - 1 >= 0 ? j - 1 : 0;
                i++;
            }else if(i == nums[j]){
                j++;
            }else{
                j++;
            }
        }else{
            f[i++] = n;
        }
    }
    cout << "here" << endl;
    int r = N/(n+1);
    int sum = 0;
    for(int i = 0; i < N; ++i){
        err[i] = abs(i / r - f[i]);
    }
    cout << sum;
}