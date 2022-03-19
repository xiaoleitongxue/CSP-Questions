#include <iostream>
using namespace std;
int main(int, char**) {
    int n;
    cin >> n;
    int counts[4] = {0, 0, 0, 0};
    int turn = 1;
    bool is_contain_7;
    int temp;
    int num;
    for(int i = 1; i < n + 1; ++i){
        is_contain_7 = false;    
        temp = i;
        while(temp > 0){
            num = temp % 10;
            if(num == 7){
                is_contain_7 = true;
                break;
            }
            temp = temp / 10;
        }    
        if(i % 7 == 0 || is_contain_7){
            n++;
            switch (turn)
            {
            case 1:
                ++counts[turn - 1];
                break;
            case 2:
                ++counts[turn - 1];
                break;
            case 3:
                ++counts[turn - 1];
                break;
            case 4:
                ++counts[turn - 1];
                break;
            default:
                break;
            }
        }
        if(turn <= 3){
            turn++;
        }else{
            turn = 1;
        }
    }
    for(int i = 0; i < 4; ++i){
        cout << counts[i] << endl;
    }
}