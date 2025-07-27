#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,a[5050][5050],m,n;
int main ()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll k;
            scanf("%lld",&k);
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+k;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k1=-1;k1<i;k1++)
            {
                for(int k2=-1;k2<j;k2++)
                {
                    if(a[i][j]-a[i-k1][j]-a[i][j-k2]+a[i-k1][j-k2]>ans)
                    {
                    	ans=a[i][j]-a[i-k1][j]-a[i][j-k2]+a[i-k1][j-k2];
					}
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

