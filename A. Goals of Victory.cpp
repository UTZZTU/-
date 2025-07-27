#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,res,k;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		res=0;
		for(int i=1;i<n;i++)
		{
			scanf("%lld",&k);
			res+=k;
		}
		printf("%lld\n",-res);
	}
	return 0;
}