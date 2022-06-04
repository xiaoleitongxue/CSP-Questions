//
// Created by lilei on 2022/3/25.
// 序列查询新解
//score 100 109ms
//特别注意数据类型要用long long
#include <iostream>
#include <numeric>

using namespace std;
int main(int, char**){
   int n, N;
   int A[100005] = {0};
   cin >> n >> N;
   for(int i = 1; i <=n; ++i){
       cin >> A[i];
   }
   A[n + 1] = N;
   int r = N / (n + 1);
   int x = 0;
   long long sum = 0;
   for(int i = 1; i <=(n + 1); ++i){
       int length = A[i] - A[i-1];
       int gx = x / r;
       int zu_nei_index = x % r;
       int temp_sum = 0;
       int cur_match_length = min(r - zu_nei_index, length);
       for(int j = -1; j < length;){
           if(cur_match_length > 0){
                temp_sum += abs(cur_match_length * gx - cur_match_length * (i - 1));
                gx++;
                j+= cur_match_length;
                cur_match_length = min(r, length - j - 1);
           }else{
               break;
           }
       }
       sum += temp_sum;
       x += length;
   }
   printf("%lld\n", sum);
}