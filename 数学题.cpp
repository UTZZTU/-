#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
ll n,x;
int main ()
{
    cin>>n>>x;
    x%=mod;
    if(x==1)
    {
        printf("%lld",qmi((ll)2,n+1,mod));
    }
    else
    {
        ll k=qmi((ll)2,n+1,mod-1);
        printf("%lld",((qmi(x,k,mod)-1)%mod+mod)%mod*qmi(x-1,mod-2,mod)%mod);
    }
    return 0;
}