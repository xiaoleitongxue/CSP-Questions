#include <iostream>
#include <cmath> //绝对值函数abs()头文件
using namespace std;

int main(){
	int n, N;
    long long sum = 0;
    cin >> n >> N;
    int A[n+2] = {0};
    A[n + 1] = N;
    for(int i =1; i <= n; ++i){
        cin >> A[i];
    }
    int r = N /( n + 1);
    for(int i = 1; i <= n + 1; ++i){
        int step = 0;
        for(int j = A[i-1]; j <= A[i] - 1; j = j + step){
            int gx = j / r;
            int gx_zu_inner_index = j % r;
            int remains = r - gx_zu_inner_index - 1;
            int end;
            if( j + remains >= A[i] - 1){
                end = A[i] - 1;
            }else{
                end  = j + remains;
            }
            step = end - j + 1;
            sum += abs(gx - (i - 1)) * (end - j + 1);
        }
    }
    cout << sum;
    return 0;
}
