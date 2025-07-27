#include <bits/stdc++.h>
using namespace std;
int t,n,m,l[1010],r[1010],f[1010],pre[1010];
void dfs(int level, int pos)
{
	f[level]=pos;
	if(l[level]!=-1) dfs(l[level],pos+1);
	if(r[level]!=-1) dfs(r[level],pos+1);
}
int find(int x,int y)
{
	int i=x,j=y;
	if(f[i]>f[j]) swap(i,j);
	while(f[j]>f[i]) j=pre[j];
	while(i!=j) i=pre[i],j=pre[j];
	return f[x]+f[y]-2*f[i];
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1,x,y;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			l[i]=x,r[i]=y;
			if(x!=-1) pre[x]=i;
			if(y!=-1) pre[y]=i;
		}
		dfs(1,0);
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",find(x,y));
		}
	}
	return 0;
}