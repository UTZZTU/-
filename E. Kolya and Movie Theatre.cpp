#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,d,a[200010],res,cnt;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		priority_queue<ll> q;
		res=cnt=0;
		scanf("%lld%lld%lld",&n,&m,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0) q.push(-1*a[i]),cnt+=a[i];
			if(q.size()>m)
			{
				cnt-=-1*q.top();
				q.pop();
			}
			res=max(res,cnt-(ll)i*d);
		}
		printf("%lld\n",res);
	}
	return 0;
}