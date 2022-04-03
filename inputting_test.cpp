#include <iostream>
using namespace std;
int main() {
    char a;
    while (cin >> a) {
        if(a == '\n'){
            break;
        }
        cout << a << endl;
    }
    return 0;
}