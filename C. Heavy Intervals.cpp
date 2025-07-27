#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,l[200010],r[200010],c[200010],sum,cnt;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sum=0;
		cnt=1;
		multiset<int> mul;
		for(int i=1;i<=n;i++) scanf("%lld",&l[i]);
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld",&r[i]);
			mul.insert(r[i]);
		}
		for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
		sort(l+1,l+1+n);
		sort(c+1,c+1+n);
		priority_queue<int> p;
		for(int i=n;i>=1;i--)
		{
			auto it=mul.lower_bound(l[i]);
//			cout<<*it<<endl;
			p.push(*it-l[i]);
			mul.erase(it);
		}
		while(!p.empty())
		{
			sum+=c[cnt++]*p.top();
			p.pop();
		}
		printf("%lld\n",sum);
	}
	return 0;
}