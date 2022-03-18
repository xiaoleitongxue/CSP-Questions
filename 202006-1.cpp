#include <iostream>
using namespace std;
int main(int, char**) {
    int n, m;
    cin >> n >> m;
    int X[n];
    int Y[n];
    char types[n];
    int theta0[m];
    int theta1[m];
    int theta2[m];
    for(int i = 0; i < n; ++i){
        cin >> X[i] >> Y[i] >> types[i];
    }
    for(int j = 0; j < m; ++j){
        cin >> theta0[j] >> theta1[j] >> theta2[j];
    }
    int value;
    char type;
    bool match;
    for(int i = 0; i < m; ++i){
        match = true;
        value = theta0[i] + theta1[i]*X[0] + theta2[i]*Y[0];
        if(value > 0){
            type = types[0];
        }else{
            if(types[0] == 'A'){
                type = 'B';
            }else{
                type = 'A';
            }
        }
        for(int j = 1; j < n; ++j){
            value = theta0[i] + theta1[i]*X[j] + theta2[i]*Y[j];
            if(value > 0 && types[j] == type){
                continue;
            }else if(value < 0 && types[j] != type ){
                continue;
            }else{
                match = false;
                break;
            }
        }
        if(match){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}