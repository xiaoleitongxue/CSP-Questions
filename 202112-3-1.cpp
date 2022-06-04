//
// Created by lilei on 2022/5/16.
// 网友的答案：100分

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define File(x) freopen("(x)", "r", stdin)
#define pf prlong longf
#define ull unsigned long long
#define db double
#define ll long long
#define MAXN
long long w, s, f;
string x;
vector<long long> v;

int main()
{
    cin >> w >> s >> x;

    long long tp = 0;
    // input data
    // the length of string is long long type
    for (long long i = 0; i < x.length(); i++)
    {
        if (x[i] >= 'A' && x[i] <= 'Z')
        {
            if (tp == 1)
            {
                v.push_back(28);
                v.push_back(28);
            }
            else if (tp == 2)
            {
                v.push_back(28);
            }
            tp = 0;
            v.push_back(x[i] - 'A');
        }
        else if (x[i] >= 'a' && x[i] <= 'z')
        {
            if (tp == 0 || tp == 2)
                v.push_back(27);
            v.push_back(x[i] - 'a');
            tp = 1;
        }
        else
        {
            if (tp != 2)
                v.push_back(28);
            tp = 2;
            v.push_back(x[i] - '0');
        }
    }

    if (v.size() % 2)
    {
        v.push_back(29);
    }
    vector<long long> v2;
    for (long long i = 0; i < v.size(); i += 2)
    {
        v2.push_back(v[i] * 30 + v[i + 1]);
    }
    // + 1 because there is a words's length
    long long len = v2.size() + 1;
    // in this case, we needn't calculate validation code
    if (s == -1)
    {
        // fill
        while (len % w)
        {
            v2.push_back(900);
            ++len;
        }
        cout << len << endl;
        for (auto x : v2)
            cout << x << endl;
        return 0;
    }
    // fill
    while ((len + (1 << (s + 1))) % w)
    {
        ++len;
        v2.push_back(900);
    }
    // computing validation code
    vector<long long> v3;
    // len = length + data + fill
    v3.push_back(len);
    // push data from v2 to v3
    for (auto X : v2)
    {
        v3.push_back(X);
    }
    // printf length, data and fill
    for (auto x : v3)
        printf("%d\n", x);

    // calculate gx
    vector<long long> v4;
    v4.push_back(1);
    v4.push_back(-3);

    long long mul = -3;
    // 1 << (s + 1) == 2^(s+1)
    //将1左移动s+1位
    for (long long i = 2; i <= (1 << (s + 1)); i++)
    {
        v4.push_back(0);
        mul = mul * 3 % 929;
        for (long long j = v4.size() - 1; j >= 1; j--){
            v4[j] += v4[j - 1] * mul % 929;
            v4[j] %= 929;
        }
            
    }
    long long w4 = 1 << (s + 1);
    for (long long i = 1; i <= w4; i++)
        v3.push_back(0);
    // calculate rx
    for (long long i = 0; i < v3.size(); i++)
    {
        long long num = v3[i];
        for (long long j = i + 1; j <= i + w4; j++)
            v3[j] -= num * v4[j - i] % 929, v3[j] %= 929;
        if (i == v3.size() - w4 - 1)
        {
            f = i + 1;
            break;
        }
    }
    // calculate validation code
    while (f < v3.size())
    {
        long long ans1 = (-v3[f]) % 929;
        if (ans1 < 0)
            ans1 += 929;
        cout << ans1 << endl;
        ++f;
    }
    return 0;
}
