//
// Created by lilei on 2022/4/3.
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<bool> flags(n + 1, false);
    flags[0] = true;
    int left, right;
    int cnt = 0;
    for(int i = 0; i < k; ++i){
        cin >> left >> right;
        if(!flags[right]){
                cnt++;
        }
            flags[left] = true;
    }
    cout << cnt << endl;
}

