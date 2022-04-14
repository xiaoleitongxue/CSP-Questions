//
// Created by lilei on 2022/3/25.
//
// score 70
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main(int, char**){
    int n;
    int N;
    cin >> n >> N;
    int nums[n + 1] = {0};
    for(int i = 1; i < n + 1; i++){
        cin >> nums[i];
    }
    long long sum = 0;
    int r = N / (n + 1);
    for(int i = 0; i < N; ++i){
        int gi = i / r;
        int fi;
        int j = gi;
        if( j > n){
            j = n;
        }
        if(i == nums[j]){
            fi = j;
        }else if(i < nums[j]){
            while(j >= 0 && i < nums[j]){
                j--;
            }
            fi = j;
        }else{
             while(j < n + 1 && i > nums[j]){
                 j++;
             }
             if(nums[j] == i){
                 fi = j;
             }else{
                 fi = j - 1;
             }
        }
        cout << gi << endl;
        sum = abs(gi - fi) + sum;
    }
    cout << sum << endl;
    return 0;
}