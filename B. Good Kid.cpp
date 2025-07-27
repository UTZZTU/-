#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[10],res;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=1;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		a[1]+=1;
		for(int i=1;i<=n;i++)
		{
			res*=a[i];
		}
		printf("%lld\n",res);
	}
	return 0;
}