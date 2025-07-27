#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1010][1010],n,m,t,k,pre[1010][1010],post[1010][1010],maxx;
int x,y;
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&f[i][j]);
		}
	}
	pre[1][1]=f[1][1];
	for(int i=2;i<=m;i++)
	{
		pre[1][i]=f[1][i]+pre[1][i-1];
	}
	for(int i=2;i<=n;i++)
	{
		pre[i][1]=f[i][1]+pre[i-1][1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			pre[i][j]=max(pre[i-1][j],pre[i][j-1])+f[i][j];
		}
	}
	post[n][m]=f[n][m];
	for(int i=m-1;i>=1;i--)
	{
		post[n][i]=f[n][i]+post[n][i+1];
	}
	for(int i=n-1;i>=1;i--)
	{
		post[i][m]=f[i][m]+post[i+1][m];
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=m-1;j>=1;j--)
		{
			post[i][j]=max(post[i+1][j],post[i][j+1])+f[i][j];
		}
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&k);
		vector<pair<int,int>> vec;
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			vec.push_back({x,y});
		}
		maxx=0;
		for(int i=0;i<vec.size();i++)
		{
			for(int j=i+1;j<vec.size();j++)
			{
				int xx1=vec[i].first,yy1=vec[i].second,xx2=vec[j].first,yy2=vec[j].second;
				maxx=max(maxx,max(pre[xx1][yy1]+post[xx2][yy2],pre[xx2][yy2]+post[xx1][yy1]));
			}
		}
		maxx=max(maxx,pre[n][m]);
		printf("%lld\n",maxx);
	}
	return 0;
}