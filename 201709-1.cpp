//
// Created by lilei on 2022/4/16.
//
#include <iostream>
using namespace std;
int main(){
    int money = 0;
    cin >> money;
    int three = 0;
    int five = 0;
    int left_money = 0;
    five = money / 50;
    three = money % 50 / 30;
    left_money = money - five * 5 * 10 - three * 3 * 10;
    int cnt = five * 5 + five * 2 + three * 3 + three + left_money / 10;
    cout << cnt;
}
