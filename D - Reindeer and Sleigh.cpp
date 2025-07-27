#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,r[200010],x;
signed main ()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&r[i]);
	}
	sort(r+1,r+1+n);
	for(int i=1;i<=n;i++)
	{
		r[i]+=r[i-1];
	}
	while(q--)
	{
		cin>>x;
		int pos=upper_bound(r+1,r+1+n,x)-r;
		pos--;
		printf("%lld\n",pos);
	}
	return 0;
}