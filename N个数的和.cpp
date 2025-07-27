#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,x,n;
inline ll read()
{
    ll x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}
int main ()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        x=read();
        ans+=x;
    }
    cout<<ans;
    return 0;
}