#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010],res;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld",&a[i]);
			res+=a[i];
		}
		int l=sqrt(res);
		if(l*l==res) puts("YES");
		else puts("NO");
	}
	return 0;
}