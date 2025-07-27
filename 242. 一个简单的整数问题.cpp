#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll tr[N],n,m,a[N],l,r,d;
char op[2];
ll lowbit(ll x)
{
	return x & -x;
}
void add(ll x,ll c)
{
	for(ll i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
ll query(ll x)
{
	ll res=0;
	for(ll i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		add(i,a[i]-a[i-1]);
	}
	while(m--)
	{
		scanf("%s%lld",op,&l);
		if(*op=='C')
		{
			scanf("%lld%lld",&r,&d);
			add(l,d),add(r+1,-d);
		}
		else
		{
			printf("%lld\n",query(l));
		}
	}
	return 0;
}