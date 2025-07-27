#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,f[N][70],a[N],q,l,r;
signed main ()
{
	scanf("%lld",&n);
//	for(int i=0;i<=60;i++)
//	{
//		cout<<((14>>i)&1)<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]<=0)
		{
			for(int j=0;j<=60;j++)
			{
				f[i][j]=f[i-1][j];
			}
		}
		else
		{
			for(int j=0;j<=60;j++)
			{
				f[i][j]=f[i-1][j]+((a[i]>>j)&1);
			}
		}
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		int res=0,k=1;
		for(int i=0;i<=60;i++)
		{
			if(f[r][i]-f[l-1][i])
			{
				res+=k;
			}
			k*=2;
		}
		printf("%lld\n",res);
	}
	return 0;
}