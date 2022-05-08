// score 100
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int compute_string(string expression){
    stack<int> nums;
    stack<char> ops;
    for(int i = 0; i < expression.length(); ++i){
        char a = expression[i];
        int left, res;
        switch (a)
        {
        case '+':
            /* code */
            ops.push('+');
            break;
        case '-':
            ops.push('+');
            nums.push(-1 * (expression[i+1] - '0'));
            i++;
            break;
        case 'x':
            left = nums.top();
            nums.pop();
            res = left * (expression[i+1] - '0');
            nums.push(res);
            ++i;
            break;
        case '/':
            left = nums.top();
            nums.pop();
            res = left / (expression[i+1] - '0');
            nums.push(res);
            ++i;
            break;
        default:
            nums.push(a - '0');
            break;
        }
    }
    while(!ops.empty()){
        char op = ops.top();
        ops.pop();
        int right = nums.top();
        nums.pop();
        int left = nums.top();
        nums.pop();
        if(op == '-'){
            nums.push(left - right);
        }else{
            nums.push(left + right);
        }
    }
    return nums.top();
}


int main(){
    int n = 0;
    cin >> n;
    string expressions[n];
    for(int i = 0; i < n; ++i){
        cin >> expressions[i];        
    }
    for(int i = 0; i < n; ++i){
        int res = compute_string(expressions[i]);
        //cout << res << endl;
        if(res == 24){
            cout << "Yes"<< endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}

/*
test case
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5


*/