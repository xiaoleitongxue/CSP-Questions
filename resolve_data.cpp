//
// Created by Joshua on 2022/4/2.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int c1, c2;
    scanf("%d %d", &c1, &c2);
    int ans = c2 - c1;      //按照题目要求做差
    if (ans % 100 >= 50) {    //四舍五入操作
        ans = ans / 100 + 1;
    } else {
        ans = ans / 100;
    }
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
    int x(3);
    cout.fill('0');
    cout.width(2);
    std::cout << x << endl;//endl causes any following text to goto the a new line.
    return 0;
}
