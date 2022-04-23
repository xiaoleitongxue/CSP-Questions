/*
//
// Created by lilei on 2022/4/23.
// score 70, 运行超时
#include <iostream>
#include <map>
int data[100001][2];

using namespace std;
int main(){
    map<int,int> mp;
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> data[i][0] >> data[i][1];
       if(mp.find(data[i][0]) == mp.end()){
            mp.insert({data[i][0], 1});
       }
    }
    map<int, int> :: iterator it;
    int max_ans = 0;
    int max_theta = 0;
    for(it = mp.begin(); it != mp.end(); it++){
        int theta = it->first;
        int prediction_success = 0;
        for(int i = 0; i < m; ++i){
            if(data[i][0] < theta){
                if(data[i][1] == 0){
                    prediction_success++;
                }
            }else{
                if(data[i][1] == 1){
                    prediction_success++;
                }
            }
        }
        if(max_ans <= prediction_success){
            max_ans = prediction_success;
            if(max_theta < theta){
                max_theta = theta;
            }
        }
    }
    cout << max_theta << endl;
    return 0;
}
*/
//差分思想
//score 100
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int m;
    cin >> m;
    vector<vector<int>> y_res(m + 1, vector<int>(2, 0));
    for(int i = 1; i < m + 1 ; ++i){
        cin >> y_res[i][0] >> y_res[i][1];
    }
    sort(y_res.begin() + 1, y_res.end(), [](vector<int> & a, vector<int> & b){
        return a[0] < b[0];
    });
    for(int i = 2; i < m + 1; ++i){
        y_res[i][1] += y_res[i-1][1];
    }
    int max_counts = 0;
    int max_theta = 0;
    int pre = -1;

    for(int i = 1; i < m + 1; ++i){
        if(pre != y_res[i][0]){
            int theta_min_index = i;
            int less_theta_counts = theta_min_index - 1 - y_res[theta_min_index-1][1];
            int equal_or_bigger_theta_counts = y_res[m][1] - y_res[theta_min_index - 1][1];
            int total = less_theta_counts + equal_or_bigger_theta_counts;
            if(total >= max_counts){
                max_counts = total;
                if(y_res[theta_min_index][0] > max_theta){
                    max_theta = y_res[theta_min_index][0];
                }
            }
        }
        pre = y_res[i][0];

    }
    cout << max_theta << endl;
    return 0;
}