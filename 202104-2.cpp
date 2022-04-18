//
// Created by lilei on 2022/4/18.
//score 70 运行超时
#include <iostream>
using namespace std;
int main(){
    int n, L, r;
    float t;
    cin >> n >> L >> r >> t;
    int matrix[600][600] = {0};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            //起始行号
            int block_i = max(0, i - r);
            //起始列号
            int block_j = max(0, j - r);

            int block_end_i = min(n - 1, i + r);
            int block_end_j = min(n - 1, j + r);
            int total = 0;
            int block_width = block_end_j - block_j + 1;
            int block_height = block_end_i - block_i + 1;
            for(int k = block_i; k <= block_end_i; ++k){
                for(int m = block_j; m <= block_end_j; ++m){
                    total += matrix[k][m];
                }
            }
            //total = total - matrix[i][j];
            float average = total / ((block_width * block_height)*1.0);
            if(average <= t){
                ans++;
            }
         }
    }
    cout << ans << endl;
}