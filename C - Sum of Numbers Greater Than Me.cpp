#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],f1[1000010],maxx,f2[1000010];
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
		f1[a[i]]++;
	}
	for(int i=1;i<=maxx;i++)
	{
		f2[i]=f2[i-1]+f1[i]*i;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",f2[maxx]-f2[a[i]]);
	}
	return 0;
}