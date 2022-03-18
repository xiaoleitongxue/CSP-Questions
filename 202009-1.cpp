#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int, char**) {
    int n, x, y;
    vector<pair<int, int>> locations;
    int X, Y;
    cin >> n >> x >> y;
    vector<pair<int,double>> distances;
    double distance;
    for(int i = 0; i < n; ++i){
        cin >> X >> Y;
        locations.push_back({X, Y});
        distance = sqrt(pow(x - X, 2) + pow(y - Y, 2));
        distances.push_back({i,distance});
    }
    sort(distances.begin(), distances.end(), [](pair<int, double> a, pair<int, double> b){
        if(a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    });
    cout << distances[0].first + 1 << endl;
    cout << distances[1].first + 1 << endl;
    cout << distances[2].first + 1 << endl;

}