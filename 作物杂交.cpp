#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,ti[2010],g[2010],reall[2010],x;
struct node{
	int a,b;
}s[2010];
int h[2010],ne[2010],cnt;
void add(int c,int a,int b)
{
	s[cnt].a=a;
	s[cnt].b=b;
	ne[cnt]=h[c];
	h[c]=cnt++;
}
int dfs(int u)
{
	if(reall[u]) return g[u];
	for(int i=h[u];~i;i=ne[i])
	{
		g[u]=min(g[u],max(ti[s[i].a],ti[s[i].b])+max(dfs(s[i].a),dfs(s[i].b)));
	}
	reall[u]=1;
	return g[u];
}
int main ()
{
	cin>>n>>m>>k>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>ti[i];
	}
	memset(g,0x3f3f3f3f,sizeof g);
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		reall[x]=1;
		g[x]=0;
	}
	for(int i=1;i<=k;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(c,a,b);
	}
	dfs(t);
	cout<<g[t];
	return 0;
}