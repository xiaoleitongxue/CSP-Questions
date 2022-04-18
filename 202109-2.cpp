#include <iostream>
#include <algorithm>
using namespace std;
//Mon Apr 18 非零度划分
//score 100
const int N = 500002;
int A[N] = {0};
//nums[i] means when height < i, delta of islands numbers
int nums[10001] = {0};
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> A[i];
    }
    //去除相邻位置重复的元素
    n = unique(A, A + n + 2) - A;
    for(int i = 1; i < n - 1; ++i){
        if(A[i] > A[i - 1] && A[i] > A[i + 1]){
            //如果海平面低于i，此处就会产生一个新的波峰
            nums[A[i]]++;
        }else if(A[i] < A[i-1] && A[i] < A[i + 1]){
            nums[A[i]]--;
        }
    }
    int max_cnt = 0;
    int sum = 0;
    for(int i = 10000; i > 0; --i){
        //sum means when height < i, numbers of islands
        sum += nums[i];
        max_cnt = max(max_cnt,sum);
    }
    cout << max_cnt;
    return 0;
}