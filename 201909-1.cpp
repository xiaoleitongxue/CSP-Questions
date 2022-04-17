#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int, char**) {
    int N, M;
    cin >> N >> M;
    int apple_counts[N] = { 0 };
    vector< vector<int> > delete_apples(N, vector<int>(2, 0));
    int delete_apple;
    int apple_sum = 0;
    for(int i = 0; i < N; ++i){
        cin >> apple_counts[i];
        for(int j = 0; j < M; ++j){
            cin >> delete_apple;
            delete_apples[i][0] = i;
            delete_apples[i][1] -= delete_apple;
        }
        apple_sum = apple_sum + apple_counts[i] - delete_apples[i][1];
    }
    sort(delete_apples.begin(), delete_apples.end(), [](vector<int> & a, vector<int> & b){
        if(a[1] == b[1]) return a[0] < b[0];
        else return a[1] > b[1];
    });
    cout << apple_sum << ' ' << delete_apples[0][0] + 1 << ' ' << delete_apples[0][1] << endl;
}