#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,r[1000010],sum[1000010];
struct node
{
	ll d,s,t;
}e[1000010];
bool check(ll x)
{
	for(int i=0;i<=n;i++) sum[i]=0;
	for(int i=1;i<=x;i++)
	{
		ll d=e[i].d,s=e[i].s,t=e[i].t;
		sum[s]+=d;
		sum[t+1]-=d;
	}
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=sum[i];
		if(res>r[i]) return false;
	}
	return true;
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&r[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i].d,&e[i].s,&e[i].t);
	}
	e[0].d=e[0].s=e[0].t=0;
	ll l=0,r=m;
	while(l<r)
	{
		ll mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	if(l==m)
	{
		cout<<0;
	}
	else
	{
		cout<<-1<<endl<<l+1;
	}
	return 0;
}