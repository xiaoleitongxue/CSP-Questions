//灰度直方图
#include <iostream>
#include <map>
using namespace std;
int main(int, char**) {
    int n;
    int m;
    int L;
    cin >> n;
    cin >> m;
    cin >> L;
    int matrix[n][m];
    map<int, int> map;
    int max = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> matrix[i][j];
            map[matrix[i][j]]++;
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }
    for(int i = 0; i < max; ++i){
        cout << map[i] << ' ';
    } 
    cout << map[max];   

}