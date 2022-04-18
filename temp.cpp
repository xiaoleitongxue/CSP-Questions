#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

//优化思路：每一行的第一个元素执行一次完整的邻域计算，对于之后的n - 1个元素，
//利用前一个元素的邻域进行计算。如此，执行时间大大降低，成功通过所有测试用例。

int main()
{
    int n, L, r, t;
    scanf("%d %d %d %d", &n, &L, &r, &t);

    //声明二维数组
    vector<vector<int>> A(n);
    for (int i = 0; i < n; i++)
    {
        A[i].resize(n);//列
    }

    //输入矩阵
    int NUM = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {//行循环
        int sum = 0, num = 0;
        for (int j = 0; j < n; j++) {//列循环

            if (j == 0) {//求每行第一个元素的邻域
                for (int x = i - r; x <= i + r; x++) {
                    if (x >= 0 && x < n) {
                        for (int y = j - r; y <= j + r; y++) {
                            if (y >= 0 && y < n) {
                                sum += A[x][y];
                                num++;
                            }
                        }
                    }
                }
                if (sum <= num * t) {
                    NUM++;
                }
            }
            else {//用此行第一个元素的邻域求剩余元素的邻域
                for (int x = i - r; x <= i + r; x++) {
                    if (x >= 0 && x < n) {
                        int y1 = j - r - 1, y2 = j + r;
                        if (y1 >= 0) {
                            sum -= A[x][y1];
                            num--;
                        }
                        if (y2 < n) {
                            sum += A[x][y2];
                            num++;
                        }
                    }
                }
                if (sum <= num * t) {
                    NUM++;
                }
            }
        }
    }

    printf("%d", NUM);

    return 0;
}

