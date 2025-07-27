#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
typedef pair<int,int> PII;
int t,n,res;
PII p[100010];
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&p[i].fi,&p[i].se);
		}
		sort(p+1,p+1+n);
		int l=1,r=n;
		while(l<r)
		{
			int minn=min(p[l].se,p[r].se);
			res+=(p[r].fi-p[l].fi)*minn;
			p[l].se-=minn;
			p[r].se-=minn;
			if(p[l].se==0) l++;
			if(p[r].se==0) r--;
		}
		printf("%lld\n",res);
	}
	return 0;
}