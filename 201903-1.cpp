#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    long n;cin>>n;
    int a[n+1];
    for(long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    double mid=0;
    long min=0,max=0;
    long temp=0;//用来保存mid的值；
    if(n%2==0)
    {
        mid=(a[n/2]+a[(n/2)+1])/2.0;//小细节：除数必须用2.0，如果用2则转换为整型
        temp=(a[n/2]+a[(n/2)+1])/2;
    }
    else
    {
        mid=a[n/2+1];
        temp=a[n/2+1];
    }
    if(a[1]<a[n])
    {
        max=a[n];
        min=a[1];
    }
    else
    {
        max=a[1];
        min=a[n];
    }
    cout<<max<<" ";
    if(mid-temp>0)
    {
        cout<<fixed<<setprecision(1)<<mid<<" ";//采用控制小数位数
    }
    else
    {
        cout<<temp<<" ";
    }
    cout<<min<<endl;
    return 0;
}

