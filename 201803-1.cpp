//
// Created by Joshua on 2022/3/22.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>
#include <iterator>
using namespace std;
int main(int, char **)
{
    string s;
    getline(cin, s);
    istringstream is(s);
    vector<int> jumps((istream_iterator<int>(is)), istream_iterator<int>());
    bool failed = false;
    vector<int> scores(jumps.size(), 0);
    for(int i = 0; i < jumps.size(); ++i){
        int cur  = jumps[i];
        switch(cur){
            case 0:{
                failed = true;
                break;
            }
            case 1:{
                scores[i] = 1;
                break;
            }
            case 2:{
                if(i == 0){
                    scores[i] = 2;
                }else if(scores[i - 1] == 1){
                    scores[i] = 2;
                }else{
                    scores[i] += scores[i - 1] + 2;
                }
                break;
            }
        }
        if(failed){
            break;
        }
    }
    cout << accumulate(scores.begin(), scores.end(), 0) << endl;
}
