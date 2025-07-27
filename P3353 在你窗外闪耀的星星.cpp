#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,w,x[100010],a,b,maxx;
signed main ()
{
	scanf("%lld%lld",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		x[a]+=b;
	}
	for(int i=1;i<=100000;i++)
	{
		x[i]+=x[i-1];
	}
	for(int i=w;i<=100000;i++)
	{
		maxx=max(maxx,x[i]-x[i-w]);
	}
	cout<<maxx;
	return 0;
}