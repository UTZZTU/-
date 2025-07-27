#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,ti[2010],g[2010],reall[2010],hh[100010],ne[100010],cnt,kk;
struct node{
	int a,b;
}s[100010];
void add(int a,int b,int c)
{
	s[cnt].a=a;
	s[cnt].b=b;
	ne[cnt]=hh[c];
	hh[c]=cnt++;
}
int dfs(int x)
{
	if(reall[x]) return g[x];
	for(int i=hh[x];~i;i=ne[i])
	{
		g[x]=min(g[x],max(ti[s[i].a],ti[s[i].b])+max(dfs(s[i].a),dfs(s[i].b)));
	}
	return g[x];
}
int main ()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ti[i]);
	}
	memset(g,0x3f3f3f3f,sizeof g);
	memset(hh,-1,sizeof hh);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&kk);
		reall[kk]=1;
		g[kk]=0;
	}
	for(int i=1,a,b,c;i<=k;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	dfs(t);
	cout<<g[t]<<endl;
	return 0;
}