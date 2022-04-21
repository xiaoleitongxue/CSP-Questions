//出行计划
#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int q_left[200002] = {0};
    int q_right[200002] = {0};
    int t, c;
    for(int i = 0; i < n; ++i){
        cin >> t >> c;
        if(k <= t){
            int l_bound = max(t - c - k + 1, 0);
            int r_bound = t - k + 1;
            q_left[l_bound]++;
            q_right[r_bound]++;
        }
    }

    for(int i = 1; i < 200002; i++){
        q_left[i] = q_left[i - 1] + q_left[i];
        q_right[i] = q_right[i-1] + q_right[i];
    }
    while(m--){
        int q;
        cin >> q;
        cout << q_left[q] - q_right[q] << endl;
    }
    return 0;
}
