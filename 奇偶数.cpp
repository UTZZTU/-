#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=55;
const int M=4005;
const int INF=0x3f3f3f;
const ull sed=31;
const int mod=1e8+7;
const double eps=1e-8;
const double PI=acos(-1.0);
typedef pair<int,int>P;
 
ll n,k;
bool judge(ll x)
{
    ll l=x,r=x+1;
    if(x&1) r--;
    ll ret=0;
    while(l<=n)
    {
        ret+=min(n,r)-l+1;
        l<<=1;
        r=(r<<1)+1;
    }
    return ret>=k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    ll l=1,r=n+1,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll tot=mid<<1;
        if(judge(tot))
        {
            ans=max(ans,tot);
            l=mid+1;
        }
        else if(judge(tot-1))
        {
            l=mid+1;
            ans=max(ans,tot-1);
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}

