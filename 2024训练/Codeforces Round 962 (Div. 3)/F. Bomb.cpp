#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[200010],b[200010],sum,pp,ct;
bool check(ll x)
{
	if(x==0) return true;
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x) continue;
		cnt+=(a[i]-x)/b[i];
		cnt++;
		if(cnt>=k) return true;
	}
	return cnt>=k;
}
void solve()
{
	sum=0;
	ct=0;
	ll l=0,r=1e9;
	cin>>n>>k;
	pp=k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++) cin>>b[j];
	while(l<r)
	{
		ll mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=l)
		{
			ll xs=(a[i]-l)/b[i];
			ll xx=a[i]-xs*b[i];
			xs++;
			pp-=xs;
			if(xx==l) ct++;
			sum+=(xs)*(a[i]+xx)/2ll;
		}
	}
	if(pp<0)
	{
		sum-=abs(pp)*l;
	}
	cout<<sum<<endl;
}
/*
7
5 6 3
13
5 3 3
18
3 3 3

*/
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}