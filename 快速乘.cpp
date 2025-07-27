#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define ll long long
ll quick_multiply(ll a,ll b)
{
    ll ans=0;
    while(b)
    {
        ans=(ans+(b%2*a)%mod)%mod;
        a=(a<<1)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<quick_multiply(a,b)<<endl;
}
