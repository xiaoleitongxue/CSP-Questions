#include <iostream>
#include <map>
using namespace std;
int main(int, char **)
{
    int n = 0;
    std::cout << "Hello, world!\n";
    n = 2;
    std::cout << n << std::endl;
    map<int, bool> mp;
    if(mp[1]){
        cout << "查询一个不存在的key" << endl;
    }else{
        mp[1] = true;
        if(mp[1]){
            cout << "插入新值" << endl;
        }
    }

}