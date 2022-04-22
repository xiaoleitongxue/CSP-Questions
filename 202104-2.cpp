
//
// Created by lilei on 2022/4/18.

/*
//score 70 运行超时
//二维差分
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
*/

//Solution 2
// two-d diff
//score 100
#include <iostream>
using namespace std;
int main(){
    int n, L, r,t;
    cin >> n >> L >> r >> t;
    int matrix[601][601] = {0};
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < n + 1; ++j){
            cin >> matrix[i][j];
        }
    }
    //计算前缀和
    //第一列
    for(int i = 1; i < n + 1; ++i){
        matrix[i][1] = matrix[i][1] + matrix[i-1][1];
    }
    for(int i = 1; i < n + 1; ++i){
        matrix[1][i] = matrix[1][i] + matrix[1][i-1];
    }
    for(int i = 2; i < n + 1; ++i){
        for(int j = 2; j < n + 1; ++j){
            matrix[i][j] = matrix[i][j] + matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < n + 1; ++j){
            //起始行号
            int block_i = max(1, i - r);
            //起始列号
            int block_j = max(1, j - r);
            int block_end_i = min(n, i + r);
            int block_end_j = min(n, j + r);
            int a = matrix[block_end_i][block_j - 1];
            int b = matrix[block_i - 1][block_end_j];
            int sum = matrix[block_end_i][block_end_j] - a - b + matrix[block_i - 1][block_j - 1];
            int block_width = block_end_j - block_j + 1;
            int block_height = block_end_i - block_i + 1;
            float average = sum / ((block_width * block_height)*1.0);
            if(average <= t){
                ans++;
            }
         }
    }
    cout << ans << endl;
    return 0;
}