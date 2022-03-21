//
// Created by Joshua on 2022/3/21.
//

#include <iostream>
#include <vector>

using namespace std;
int main(int, char**){
    int n;
    cin >> n;
    vector<int> first_day_prices;
    vector<int> second_day_prices(n);
    int value;
    for(int i = 0; i < n; ++i){
        cin >> value;
        first_day_prices.push_back(value);
    }
    for(int i = 0; i < n; ++i){
        if(i == 0){
            second_day_prices[i] = (first_day_prices[i] + first_day_prices[i+1]) / 2;
        }else if(i == n - 1){
            second_day_prices[i] = (first_day_prices[i] + first_day_prices[i-1]) / 2;
        }else{
            second_day_prices[i] = (first_day_prices[i] + first_day_prices[i-1] + first_day_prices[i + 1]) / 3;
        }
        if(i == n - 1){
            cout << second_day_prices[i] << endl;
        }else{
            cout << second_day_prices[i] << ' ';
        }
    }

}
