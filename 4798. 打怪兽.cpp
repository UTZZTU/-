#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1010],dp[1010],f[1010],pos;
bool check(int x)
{
	if(!x)
	return true;
	for(int i=1;i<=x;i++)
	{
		f[i]=a[i];
	}
	sort(f+1,f+1+x);
	for(int i=1;i<=x;i++)
	{
		if(i==1)
		dp[i]=a[i];
		else
		{
			dp[i]=min(dp[i-1]+f[i],dp[i-2]+max(f[i-1],f[i]));
		}
	}
	if(dp[x]<=m)
	return true;
	else
	return false;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	int l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	cout<<l;
	return 0;
}