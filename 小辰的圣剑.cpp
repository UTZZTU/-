#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,a[5010],b[5010];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(b[i]-b[i-x]<=u&&a[i]-a[i-x]<=m) return true;
	}
	return false;
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&m,&u);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
//		cout<<a[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		b[i]+=b[i-1];
	}
	int l=0,r=n;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}