//
// Created by lilei on 2022/3/25.
//
// score 100
#include <iostream>
#include <numeric>

using namespace std;
int main(int, char**){
    int n, N;
    cin >> n >> N;
    int nums[100002] = {0};
    nums[n+1] = N;
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    int r = N /(n+1);
    long long sum = 0;
    for(int i = 1; i <= n + 1; ++i){
        int cur_fx = i - 1;
        int step = 0;
        for(int j = nums[i - 1]; j <= nums[i] - 1; j = j + step){
            int gx = j / r;
            int gx_group_inner_index = j % r;
            int remains = r - gx_group_inner_index - 1;
            int end = 0;
            if(j + remains >= nums[i] - 1){
                end = nums[i] - 1;
                step = end - j + 1;
            }else{
                end = j + remains;
                step = remains + 1;
            }
            sum += abs(gx - cur_fx)*(end - j + 1);
        }
    }

    cout << sum << endl;
}