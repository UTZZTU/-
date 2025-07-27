#include <iostream>
#include <cstdio>
using namespace std;
int sum;
void find(int star,int m)
{
    int i;
    for (i=star; i<=m; i++)
    {
        if(m%i==0 && i<=m/i)//当能整除，且小于后一个数
        {
            sum++;
            find(i,m/i);
        }
        if(i>m/i)//前一个数比后一个数大
            break;
    }
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        sum=1;//默认a=a的这种情况；
        cin>>n;
        find(2,n);//从2开始
        cout<<sum<<endl;
    }
    return 0;
} 