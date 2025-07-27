#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int f[N],n,k,m,c,d,a[N],res;
bool check(int x)
{
	res=0;
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) res++;
		if(res>=k) return true;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) continue;
		int pos=min(i-1,m-1);
		if(a[i]+d*pos+c<x) continue;
		f[max(m,i)]++;
		if(a[i]+c>=x) f[min(n+1,i+m)]--;
		else
		{
			int cz=x-a[i]-c,cnt;
			if(cz%d==0) cnt=cz/d-1;
			else cnt=cz/d;
			f[min(n+1,i+m-1-cnt)]--;
		}
	}
	for(int i=m;i<=n;i++)
	{
		res+=f[i];
		if(res>=k) return true;
	}
	return false;
}
signed main ()
{
	scanf("%lld%lld%lld%lld%lld",&n,&k,&m,&c,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int l=0,r=1e18;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}