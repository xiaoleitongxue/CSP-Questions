#include <iostream>
using namespace std;
struct Trash{
    int x;
    int y;
};
int n;
Trash Trashs[1000] = {0};
int scores[5] = {0};
bool find_xy(int x, int y){
    for(int i = 0; i < n; ++i){
        if(Trashs[i].x == x && Trashs[i].y == y){
            return true;
        }
    }
    return false;
}
bool is_trash(Trash t){
    int x = t.x;
    int y = t.y;
    return find_xy(x - 1, y) && find_xy(x, y + 1) && find_xy(x + 1, y) && find_xy(x, y - 1);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> Trashs[i].x >> Trashs[i].y;
    }
    
    for(int i = 0; i < n; ++i){
        int x= Trashs[i].x;
        int y = Trashs[i].y;
        if(is_trash(Trashs[i])){
            int score = 0;
            if(find_xy(x + 1, y - 1)){
                score++;
            }
            if(find_xy(x + 1, y + 1)){
                score++;
            }
            if(find_xy(x - 1, y + 1)){
                score++;
            }
            if(find_xy(x - 1, y - 1)){
                score++;
            }
            scores[score]++;
        }
    }

    for(int i = 0; i < 5; ++i){
        cout << scores[i] << endl;
    }
    return 0;

}