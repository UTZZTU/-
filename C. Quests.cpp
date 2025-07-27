#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,a[200010],b[200010],pre[200010],maxx,res;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		multiset<int> mul;
		maxx=res=0;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			pre[i]=a[i]+pre[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
		}
		for(int i=1;i<=min(n,k);i++)
		{
			mul.insert(b[i]);
		}
		for(int i=min(n,k);i>=1;i--)
		{
			int cnt=k-i;
			res=pre[i]+cnt*(int)(*mul.rbegin());
			maxx=max(maxx,res);
			mul.erase(mul.lower_bound(b[i]));
//			cout<<res<<" "<<i<<endl;
		}
		printf("%lld\n",maxx);
	}
	return 0;
}