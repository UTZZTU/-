#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sum;
ll a[100010],f[100010];
int main()
{
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;i++)
    cin>> a[i];
    sort(a+1,a+n+1);
    for(ll i = 2;i<=n;i++)
    f[i]=a[i]-a[i-1];
    ll temp=0,cnt=1;
    for(ll i = n;i>1;i--,cnt++)
    {
        temp+=f[i]*cnt;
        sum+=temp;
    }cout<<sum;
    return 0;
}

