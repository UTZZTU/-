#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100010],b[100010],res;
signed main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i>=2)
		{
			res+=abs(a[i]-a[i-1]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
		if(i>=2)
		{
			res+=abs(b[i]-b[i-1]);
		}
	}
	cout<<res;
	return 0;
}