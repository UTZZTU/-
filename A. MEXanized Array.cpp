#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,x,res;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&x);
		if(x<k-1||n<k)
		{
			puts("-1");
		}
		else
		{
			res=k*(k-1)/2;
			if(x>k) res+=(n-k)*x;
			else if(x==k)
			{
				res+=(n-k)*(x-1);
			}
			else
			{
				res+=(n-k)*x;
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}