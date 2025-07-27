#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,c[200010],res;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&c[i]);
		}
		for(int i=2;i<=n;i++)
		{
			if(c[i]>=c[i-1])
			{
				;
			}
			else
			{
				res+=c[i-1]-c[i];
			}
		}
		res+=c[n];
		printf("%lld\n",res-1);
	}
	return 0;
}