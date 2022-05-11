#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct nums{
    int id;
    //increasing order
    // a is left operand
    bool operator<(const nums & a) const{
        return id > a.id;
    }
};
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
    nums arr[3];
    arr[0].id = 2;
    arr[1].id = 1;
    arr[2].id = 3;
    priority_queue<nums> p;
    for(int i = 0; i < 3; ++i){
        p.push(arr[i]);
    }
    for(int i = 0; i < 3; ++i){
        cout << p.top().id << endl;
        p.pop();
    }

}