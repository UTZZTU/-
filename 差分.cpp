#include <bits/stdc++.h>
using namespace std;
int n,m,f[100010],cf[100010],ans;
int main ()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        cf[i]=f[i]-f[i-1];
    }
    for(int i=1,l,r,c;i<=m;i++)
    {
        scanf("%d %d %d",&l,&r,&c);
        cf[l]+=c;
        cf[r+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        ans+=cf[i];
        cout<<ans<<" ";
    }
    return 0;
}