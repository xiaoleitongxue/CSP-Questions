//
// Created by lilei on 2022/3/24.
//
#include <iostream>
#include <vector>
using namespace std;
int main(int, char **)
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    int res = INT32_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            res = min(res, abs(nums[i] - nums[j]));
        }
    }
    cout << res;
}

