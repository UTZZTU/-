#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010],n;
int qd,zd,wz;
int main ()
{
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    ll maxx=0;
    ll maxn=a[0];
    wz=0;
    for(int i=0;i<n;i++)
    {
        if(maxx<0)
        {
            maxx=0;
            wz=i;
        } 
        maxx+=a[i];
        if(maxx>maxn)
        {
            maxn=maxx;
            qd=wz;
            zd=i;
        }
    }
    
    cout<<qd<<" "<<zd;
    return 0;
}