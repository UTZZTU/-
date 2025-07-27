#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int color[40][N],n,m,u,v,w,e[2*N],W[2*N],ne[2*N],h[N],cnt,sum;
void add(int a,int b,int c)
{
	e[cnt]=b;
	W[cnt]=c;
	ne[cnt]=h[a];
	h[a]=cnt++;
}
int dfs(int j,int i,int itcolor)
{
	sum++;
	color[i][j]=itcolor;
	int res=itcolor;
	for(int k=h[j];~k;k=ne[k])
	{
		int v=e[k];
		if(color[i][v]==-1)
		{
			res+=dfs(v,i,(((W[k]>>i)&1)^itcolor));
		}
		else if(color[i][v]!=(((W[k]>>i)&1)^itcolor))
		{
			printf("-1");
			exit(0);
		}
	}
	return res;
}
int main ()
{
	memset(color,-1,sizeof color);
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	ll p=1;
	ll res=0;
	for(int i=0;i<31;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(color[i][j]==-1)
			{
				sum=0;
				ll t=dfs(j,i,(ll)1);
				res+=p*(ll)min(t,sum-t);
			}
		}
		p<<=1;
	}
	printf("%lld",res);
	return 0;
}