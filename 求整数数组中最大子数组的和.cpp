#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,a[5050][5050],m,n,f[5050];
ll fun(int x,int y)
{
    memset(f,0,sizeof(f));
    for(int i=x;i<=y;i++)
    {
        for(int j=1;j<=n;j++)
            f[j]+=a[i][j];
    }
    ll maxx=f[0];
    ll maxn=maxx;
    for(int i=1;i<=n;i++)
    {
        if(maxx<0)
            maxx=0;
        maxx+=f[i];
        if(maxx>maxn)
            maxn=maxx;
    }
    return maxn;
}
int main ()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        scanf("%lld",&a[i][j]);
    }
    for(int i=1;i<m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            ans=max(ans,fun(i,j));
        }
    }
    cout<<ans;
    return 0;
}

