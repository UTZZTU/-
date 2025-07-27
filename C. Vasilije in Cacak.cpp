#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,x,minn,maxx;
int get_num(int l,int r)
{
	return (l+r)*(r-l+1)/2;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&x);
		minn=get_num((int)1,k);
		maxx=get_num(n-k+1,n);
		if(x>=minn&&x<=maxx) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}