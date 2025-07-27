#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int t,ne[2*N],h[2*N],e[2*N],idx,n,u,v,q,x,y,vis[N],f[2*N];
void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u)
{
	f[u]=0;
	vis[u]=1;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(!vis[j])
		{
			f[u]+=dfs(j);
		}
	}
	if(f[u]==0) f[u]++;
	return f[u];
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		idx=0;
		memset(h,-1,sizeof h);
		memset(vis, 0,sizeof vis);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&y);
//			printf("case: %d %d\n",f[x],f[y]);
			printf("%lld\n",(long long)f[x]*f[y]);
		}
	}
	return 0;
}