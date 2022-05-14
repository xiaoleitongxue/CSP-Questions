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
    int k = pow(2, s + 1);
    int data_counts = words.size() - 1;
    int tianchong_counts = 0;
    int cur = 1 + data_counts + k;
    while(cur % 4 != 0){
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
    vector<item> gx;
    for(int i = 0; i < k; ++i){

    }
}