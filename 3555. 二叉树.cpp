#include <bits/stdc++.h>
using namespace std;
int t,n,m,fa[1010],l[1010],r[1010],depth[1010];
void sz()
{
	for(int i=1;i<=n;i++)
	fa[i]=i;
}
void dfs(int x,int deep)
{
	if(x==-1)
	return;
	depth[x]=deep;
	dfs(l[x],deep+1);
	dfs(r[x],deep+1);
}
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(depth,0,sizeof(depth));
		scanf("%d %d",&n,&m);
		sz();
		for(int j=1,x,y;j<=n;j++)
		{
			scanf("%d %d",&x,&y);
			if(x!=-1)
			fa[x]=j;
			if(y!=-1)
			fa[y]=j;
			l[j]=x;
			r[j]=y;
		}
		dfs(1,0);
		for(int j=1,u,v;j<=m;j++)
		{
			scanf("%d %d",&u,&v);
			int len1=0,len2=0;
			while(u!=v)
			{
				if(depth[u]<depth[v])
				{
					v=fa[v];
					len2++;
				}
				else
				{
					u=fa[u];
					len1++;
				}
			}
			cout<<len1+len2<<endl;
		}
	}
	return 0;
}