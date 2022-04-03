#include<iostream>
#define endl '\n'
#define int long long
using namespace std;

const int N = 1e6 + 10;

int n;
int a[N], p[N];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > a[i - 1])
        {
            p[a[i - 1] + 1]++;
            p[a[i] + 1]--;
        }
    }

    int res = 0;
    for (int i = 1; i <= 1e4; i++)
    {
        p[i] += p[i - 1];
        res = max(res, p[i]);
    }

    cout << res << endl;
    return 0;
}

