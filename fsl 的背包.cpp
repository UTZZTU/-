#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
#define fi first
#define se second
int n,m,k,res;
PII p[1000010];
bool check(int x)
{
	int cnt=0,t=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=k/2&&p[i].se < x) continue;
		if(cnt<k/2&&p[i].se < x) cnt++;
		sum+=p[i].fi;
		t++;
		if(t==k) break;
	}
	if(t<k||sum>m) return false;
	return true;
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i].fi);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i].se);
	}
	sort(p+1,p+1+n);
	int l=0,r=1e9+10;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	if(l==0) printf("-1");
	else printf("%lld",l);
	return 0;
}