#include <iostream>
using namespace std;
int main(int, char**) {
    int n;
    int weight;
    int score;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> weight;
        cin >> score;
        sum += weight * score;
    }
    cout << max(0, sum) << endl;
}