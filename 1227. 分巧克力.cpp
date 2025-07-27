#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,h[100010],w[100010],l,r,mid,ans;
bool check(ll x)
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(h[i]/x)*(w[i]/x);
		if(ans>=k)
		return true;
	}
	return false;
}
int main ()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d %d",&h[i],&w[i]);
	l=1,r=1e5;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	cout<<l;
	return 0;
}