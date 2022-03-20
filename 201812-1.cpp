#include <iostream>
#include <vector>
using namespace std;
//r = 1 g = 3 y = 2
int main(int, char**) {
    std::cout << "Hello, world!\n";
    vector<int> light_color_order(3,0);
    for(int i = 0; i < 3; ++i){
        cin >> light_color_order[i];
    }
    int temp;
    temp = light_color_order[2];
    light_color_order[2] = light_color_order[1];
    light_color_order[1] = temp;
    int n;
    cin >> n;
    vector<pair<int, int>> k_t(n);
    for(int i = 0; i < n; ++i){
        cin >> k_t[i].first >> k_t[i].second;
    }
    int time = 0;
    for(int i = 0; i < n; i++){
        switch(k_t[i].first){
            case 0:{
                time += k_t[i].second;
                break;
            }
            case 1:{
                time += k_t[i].second;
                break;
            }
            case 2:{
                int temp = k_t[i].second + light_color_order[0];
                time += temp;
                break;
            }case 3:{
                break;
            }default:{
                break;
            }
        }
    }
    cout << time << endl;

}