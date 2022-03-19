#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(int, char **)
{
    int n;
    cin >> n;
    vector<float> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    float mid;
    if (a.size() % 2 == 0)
    {
        mid = (a[a.size() / 2 - 1] + a[a.size() / 2]) / 2;
    }
    else
    {
        mid = a[a.size() / 2];
    }
    cout << int(a[a.size() - 1]) << ' ';
    if(mid == float(int(mid))){
        cout << int(mid);
    }else{
        if(mid > 0.0){
            mid = mid + 0.5;
        }else{
            mid = mid - 0.5;
        }
        cout << fixed << setprecision(1) << mid;
    }
    cout << ' ' << int(a[0]) << endl;
}