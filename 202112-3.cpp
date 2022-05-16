//score 20
using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
long long w, s;
string str;

vector<long long> calc_gx(long long k){
    vector<long long> gx(k + 1, 0);
    gx[0] = -3;
    gx[1] = 1;
    //computing items from 3^2 to 3^k
    for(long long i = 2; i <= k; i++){
        vector<long long> temp;
        temp.assign(gx.begin(), gx.end());
        for(long long j = 1; j <= temp.size(); j++){
            gx[j] = temp[j - 1];
        }
        gx[0] = 0;
        for(long long j = 0; j < temp.size(); j++){
            temp[j] *= (-pow(3, i));
            gx[j] += temp[j];
        }
    }
    return gx;
}

vector<long long> calc_dx(vector<long long> words){
    vector<long long> dx;
    for(long long i = words.size() - 1; i >= 0; --i){
        dx.push_back(words[i]);
    }
    return dx;
}

vector<long long> calc_rx(long long k, vector<long long> words){
    vector<long long> gx = calc_gx(k);
    vector<long long> dx = calc_dx(words);

    //x^k*d(x)
    vector<long long> kdx(dx.size() + k, 0);
    for(long long i = 0; i < dx.size(); ++i){
        kdx[i + k] = dx[i];
    }
    // calc kdx % gx
    long long kdx_len = kdx.size();
    long long gx_len = gx.size();
    long long kdx_index = kdx_len - 1;
    while(kdx_index >= gx_len - 1){
        long long xishu = kdx[kdx_index] / gx[gx_len - 1];
        long long dx_index = gx_len - 1;
        for(long long i = kdx_index; i > kdx_index - gx_len; --i){
            kdx[i] -= (gx[dx_index--] * xishu);
        }
        kdx_index--;
    }
    vector<long long> rx;
    long long i = gx_len - 2;
    while(kdx[i] == 0){
        i--;
    }
    for(; i >= 0; --i){
        kdx[i] = (-kdx[i]);
        rx.push_back(kdx[i]);
    }
    return rx;
}

int main(){
    cin >> w >> s;
    cin >> str;
    vector<long long> nums;
    map<pair<long long, long long>, vector<long long>> rules;
    rules[make_pair(0, 1)] = vector<long long>{27};
    rules[make_pair(0, 2)] = vector<long long>{28};
    rules[make_pair(1, 0)] = vector<long long>{28, 28};
    rules[make_pair(1, 2)] = vector<long long>{28};
    rules[make_pair(2, 0)] = vector<long long>{28};
    rules[make_pair(2, 1)] = vector<long long>{27};
    vector<long long> codes;
    long long from = -1;
    long long to = 0;
    for(long long i = 0; i < str.length(); ++i){
        char c = str[i];
        long long code = 0;
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
            for(long long j = 0; j < rules[make_pair(from, to)].size(); ++j){
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
    vector<long long> words;
    words.push_back(0);
    for(long long i = 0; i < codes.size(); i = i + 2){
        words.push_back(30*codes[i] + codes[i + 1]);
    }
    long long k;
    if(s == -1){
        k = 0;
    }else{
        k = pow(2, s + 1);
    }
    long long data_counts = words.size() - 1;
    long long tianchong_counts = 0;
    long long cur = 1 + data_counts + k;
    while(cur % w != 0){
        cur++;
    }
    tianchong_counts = cur - (1 + data_counts + k);
    words[0] = data_counts + tianchong_counts + 1;
    for(long long i = 0; i < tianchong_counts; ++i){
        words.push_back(900);
    }
    vector<long long> rx = calc_rx(k, words);
    vector<long long> jx;
    for(long long i = 0; i < rx.size(); ++i){
        if(rx[i] < 0){
            jx.push_back((rx[i] % 929 + 929) % 929);
        }else{
            jx.push_back(rx[i] % 929);
        }
    }
    for(long long i = 0; i < jx.size(); ++i){
        words.push_back(jx[i]);
    }
    for(long long i = 0; i < words.size(); ++i){
        cout << words[i] << endl;
    }
    return 0;
}