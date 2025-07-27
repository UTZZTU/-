#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,t[100010],c[100010];
bool check(int x)
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(t[i]>x)
		{
			res+=c[i]*(t[i]-x);
			if(res>m) return false;
		}
	}
	return res<=m;
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&t[i],&c[i]);
	}
	int l=k,r=100000;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}