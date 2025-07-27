#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N=2e6+3;
ll a[N+10],sum[N+10];
ll get_id(ll x) // 得到组号
{
    return (ll)(lower_bound(a+1,a+N+1,x)-a);
}
int main()
{
    ios::sync_with_stdio(false);
    for(ll i=1;i<=N;i++)
    {
        a[i]=(1+i)*i/2; // 前i组个数
        sum[i]=sum[i-1]+a[i]; // 前i组的和
    }
    int T;cin>>T;
    ll l,r,ans;
    while(T--)
    {
        cin>>l>>r;
        ll n1=get_id(l);
        ll n2=get_id(r);
        if(n1==n2) // 同一组
        {
            ll num=r-l+1;
            ll x=l-a[n1-1];
            ans=x*num+num*(num-1)/2;
        }
        else
        {
            ll num=a[n1]-l+1;
            ll x=l-a[n1-1];
            ll s1=x*num+num*(num-1)/2; // 前面部分
            ll s2=sum[n2-1]-sum[n1]; // 中间的完整组
            num=r-a[n2-1];
            ll s3=num+num*(num-1)/2; // 最后部分
            ans=s1+s2+s3;
        }
        printf("%llu\n",ans);
    }
    return 0;
}
