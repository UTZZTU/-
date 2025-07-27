#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,c[200010],u,m,f[200010],yy[200010];
vector<ll> vec[200010];
ll dfs(int x)
{
	if(yy[x]==0) return c[x];
	if(yy[x]!=0&&vec[x].size()==0) return (ll)0;
	ll res=0;
	for(ll i=0;i<vec[x].size();i++)
	{
		res+=dfs(vec[x][i]);
	}
	f[x]=min(res,c[x]);
	return min(res,c[x]);
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++) scanf("%lld",&c[i]),f[i]=-1;
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&u);
			c[u]=0;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&m);
			yy[i]=m;
			vector<ll> v;
			for(int j=1;j<=m;j++)
			{
				scanf("%lld",&u);
				if(c[u]!=0)
				v.push_back(u);
			}
			vec[i]=v;
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0) printf("0 ");
			else if(f[i]!=-1) printf("%lld ",f[i]);
			else printf("%lld ",dfs((ll)i));
		}
		printf("\n");
	}
	return 0;
}