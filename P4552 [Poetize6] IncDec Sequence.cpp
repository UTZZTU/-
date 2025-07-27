#include<iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main ()
{
    ll a[100010],n,i,zs=0,fs=0,c;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
        for(i=n;i>1;i--)
        	a[i]-=a[i-1];
    for(i=2;i<=n;i++)
    {
        if(a[i]>0)
        zs+=a[i];
        else if(a[i]<0)
        {
        	fs-=a[i];
		}
    }
    cout<<max(zs,fs)<<endl;
    cout<<abs(zs-fs)+1;
}