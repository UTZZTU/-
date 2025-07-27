#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,k,f[1010][1010],a[1010],res;
int main ()
{
	scanf("%lld%lld",&n,&k);
	k=n-k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		f[i][1]=1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]%a[i]==0)
			{
				for(int m=2;m<=k;m++)
				{
					f[j][m]=(f[j][m]+f[i][m-1])%mod;
				}
			}
		}
		res=(res+f[i][k])%mod;
	}
	printf("%lld",res);
	return 0;
}