#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[510][510],res,n;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&f[i][j]);
		}
	}
	for(int i=n;i>=2;i--)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				f[k][j]=f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
				if(j>=i) res+=2*f[j][k];
			}
		}
	}
	cout<<res;
	return 0;
}