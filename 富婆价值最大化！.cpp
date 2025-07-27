#include<bits/stdc++.h>
#define int long long
#define M 1000005
using namespace std;
int a[M];
int ans[M];
int dp[M];
signed main()
{
    int n,q;
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    int now=-0x3f3f3f3f;
    int num=1;
    dp[0]=now;
    int p0=0;
    int ans0=0;
    int pre=0;
    for(int i=1;i<=n;i++)
    {
        
        dp[i]=max(dp[i-1]+a[i],a[i]);
        if(dp[i]==now)
            num+=p0+1;
        else if(dp[i]>now)
            num=1+p0,now=dp[i];
        if(dp[i]==0)
            p0++;
        else if(dp[i]<0)
            p0=0;
            ans[i]=num;
    }
    for(int i=1;i<=q;i++)
    {
        int qu;
        scanf("%lld",&qu);
        printf("%lld\n",ans[qu]);
    }
    return 0;
}