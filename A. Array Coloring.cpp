#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100],res;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]&1) res++;
		}
		if(res&1) puts("NO");
		else puts("YES");
	}
	return 0;
}