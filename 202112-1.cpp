//序列查询
//score 100 0ms 3.167MB
#include <iostream>
using namespace std;
int main(int, char**) {
    int n, N;
    int A[201]= {0};
    cin >> n >> N;
    for(int i = 1; i <= n; ++i){
        cin >> A[i];
    }
    int sum = 0;
    int count = 0;
    for(int i = 1; i <= n; ++i){
        sum += (A[i] - A[i - 1]) * (i - 1);
        count+= (A[i] - A[i - 1]);
    }
    sum += (N - count) * n;
    printf("%d\n", sum);
}