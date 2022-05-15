using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctype.h>
#include <math.h>
int w, s;
string str;
struct item{
    int dishu;
    int exp;
};


vector<int> calc_gx(int k){
    vector<int> gx(k + 1, 0);
    gx[0] = -3;
    gx[1] = 1;
    // 之后还有K - 1项需要计算
    for(int i = 2; i <= k; i++){
        vector<int> temp;
        temp.assign(gx.begin(), gx.end());
        gx[0] = 0;
        for(int j = 1; j <= k; j++){
            gx[j] = temp[j - 1];
        }
        for(int j = 1; j <= k; j++){
            temp[j] *= -pow(3, i);
            gx[j] += temp[j];
        }
    }
    return gx;
}

vector<int> calc_dx(vector<int> words){
    vector<int> dx;
    for(int i = words.size() - 1; i >= 0; --i){
        dx.push_back(words[i]);
    }
    return dx;
}

vector<int> calc_rx(int k, vector<int> words){
    vector<int> gx = calc_gx(k);
    vector<int> dx = calc_dx(words);
    //dx % gx = rx
    cout << "gx and dx has calc" << endl;
    //x^k*d(x)
    vector<int> kdx(dx.size() + k, 0);
    for(int i = 0; i < dx.size(); ++i){
        kdx[i + k] = dx[i];
    }
    //
    // calc kdx % gx
    int kdx_len = kdx.size();
    int gx_len = gx.size();
    while(kdx_len >= gx_len){
        int xishu = kdx[kdx_len - 1] / gx[gx_len - 1];
        int i_dx = gx_len - 1;
        for(int i = kdx_len - 1; i >= kdx_len - gx_len; --i){
            kdx[i] -= (gx[i_dx--]) * xishu;
        }
        kdx_len--;
    }
    for(int i = 0; i < kdx.size(); i++){
        cout << kdx[i] << ' ';
    }
    cout << endl;
    vector<int> rx;
    int i = gx_len - 2;
    while(kdx[i] == 0){
        i--;
    }
    for(; i >= 0; --i){
        kdx[i] = (-kdx[i]);
        if (kdx[i] < 0)
            kdx[i] += 929;
        rx.push_back(kdx[i]);
    }
    for(int i = 0; i < rx.size(); i++){
        cout << rx[i] << ' ';
    }
    cout << endl;
    return rx;
}

int main(){
    cin >> w >> s;
    cin >> str;
    vector<int> nums;
    map<pair<int, int>, vector<int>> rules;
    rules[make_pair(0, 1)] = vector<int>{27};
    rules[make_pair(0, 2)] = vector<int>{28};
    rules[make_pair(1, 0)] = vector<int>{28, 28};
    rules[make_pair(1, 2)] = vector<int>{28};
    rules[make_pair(2, 0)] = vector<int>{28};
    rules[make_pair(2, 1)] = vector<int>{27};
    //cout << rules[make_pair(1, 0)][0] << endl;
    vector<int> codes;
    int from = -1;
    int to = 0;
    for(int i = 0; i < str.length(); ++i){
        char c = str[i];
        int code = 0;
        if(isdigit(c)){
            code = c - '0';
            to = 2;
        }else{
            if(isupper(c)){
                to = 0;
                code = c - 'A';
            }else{
                to = 1;
                code = c - 'a';
            }
        }
        if(rules[make_pair(from, to)].size()){
            for(int j = 0; j < rules[make_pair(from, to)].size(); ++j){
                codes.push_back(rules[make_pair(from, to)][j]);
            }
            codes.push_back(code);
        }else{
            codes.push_back(code);
        }
        from = to;
    }
    
    
    if(codes.size() % 2 != 0){
        codes.push_back(29);
    }
    for(int code : codes){
        cout << code << ' ';
    }
    cout << endl;
    vector<int> words;
    words.push_back(0);
    for(int i = 0; i < codes.size(); i = i + 2){
        words.push_back(30*codes[i] + codes[i + 1]);
    }
    int k;
    if(s == -1){
        k = 0;
    }else{
        k = pow(2, s + 1);
    }
    int data_counts = words.size() - 1;
    int tianchong_counts = 0;
    int cur = 1 + data_counts + k;
    while(cur % w != 0){
        cur++;
    }
    cout << cur << endl;
    tianchong_counts = cur - (1 + data_counts + k);
    cout << data_counts << ' ' << k << endl;
    words[0] = data_counts + tianchong_counts + 1;
    cout << tianchong_counts << endl;
    for(int i = 0; i < tianchong_counts; ++i){
        words.push_back(900);
    }
    for(int i = 0; i < words.size(); i++){
        cout << words[i] << ' ';
    }
    cout << endl;
    vector<int> rx = calc_rx(k, words);
    vector<int> jx;
    for(int i = 0; i < rx.size(); ++i){
        jx.push_back(rx[i] % 929);
    }
    for(int i = jx.size() - 1; i >= 0; --i){
        words.push_back(jx[i]);
    }
    for(int i = 0; i < words.size(); ++i){
        cout << words[i] << endl;
    }
    return 0;
}