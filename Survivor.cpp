#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[200010],b[200010],c[200010];
bool check(ll x)
{
	ll f,sum=0,t;
	priority_queue<ll ,vector<ll>,greater<ll> >q;
	for(int i=1;i<=n;i++)
	{
		t=ceil(((m*b[i])-a[i])*1.0/c[i]);
		f=max((ll)0,t);
		q.push(f);
	}
	for(int i=1;i<=x;i++)
	{
		sum+=q.top();
		q.pop();
	}
	return sum<=k;
}
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
	scanf("%lld",&c[i]);
	ll l=0,r=n,mid;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	cout<<l;
	return 0;
}