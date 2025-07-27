#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,k,x[1000010],maxx;
signed main ()
{
	scanf("%lld%lld%lld",&n,&l,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	sort(x+1,x+1+n);
	for(int i=1;i<=n;i++)
	{
		int pre=(i-k+n-1)%n;
		if(pre==0) pre=n;
		maxx=max(maxx,(x[i]-x[pre]+l)%l);
	}
	printf("%lld",maxx);
	return 0;
}