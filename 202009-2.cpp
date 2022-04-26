// score 100
#include <iostream>
using namespace std;
int main()
{
    int n, k, t, x_l, y_d, x_r, y_u;
    cin >> n >> k >> t >> x_l >> y_d >> x_r >> y_u;
    int x_t, y_t;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i)
    {
        int passing = 0;
        int stay_continuous = 0;
        int record[1002] = {0};
        for (int j = 1; j < t + 1; ++j)
        {
            cin >> x_t >> y_t;
            if (x_t >= x_l && x_t <= x_r && y_t >= y_d && y_t <= y_u)
            {
                passing++;
                record[j] = 1;
                record[j] += record[j - 1];
                stay_continuous = max(stay_continuous, record[j]);
            }
        }
        if (passing > 0)
        {
            a++;
            if (stay_continuous >= k)
            {
                b++;
            }
        }
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}