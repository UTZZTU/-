#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define pi acos(-1.0)
#define ms(a,b) memset(a,b,sizeof(a))
#define nl endl
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long ll;
ll qpow(ll x, ll y, ll mod){ll s=1;while(y){if(y&1)s=s*x%mod;x=x*x%mod;y>>=1;}return s;}
//ll qpow(ll a, ll b){ll s=1;while(b>0){if(b%2==1)s=s*a;a=a*a;b=b>>1;}return s;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f;}
 
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans = n, tn = n;
        for(int i=2;i*i<=n;i++)
            while(tn%i==0)
                tn /= i, ans = i;
       // cout<<tn << " -- " <<ans<<nl;
        ans = max(tn,ans);
        if(n == 1) puts("0");
        else cout<<(n/ans)<<nl;
    }
    return 0;
}

