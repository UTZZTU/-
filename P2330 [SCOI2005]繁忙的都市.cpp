#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define il inline
#define re register
il int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
struct Edge
{
	int u,v,w;
}e[maxn];
int cnt,fa[5050],n,m,maxm=0,eu,ev,tot;
il void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}
il bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
il int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
il void kruskal()
{
	sort(e+1,e+1+m,cmp);
	for(re int i=1;i<=m;i++)
	{
		eu=find(e[i].u);ev=find(e[i].v);
		if(eu==ev)
		continue;
		if(e[i].w>maxm)
		maxm=e[i].w;
		fa[ev]=eu;
		if(++tot==n-1)
		break;
	}
}
int main ()
{
	n=read();m=read();
	for(re int i=1;i<=n;i++)
	fa[i]=i;
	for(re int i=1,u,v,w;i<=m;i++)
	{
		u=read();v=read();w=read();
		add(u,v,w);
	}
	kruskal();
	cout<<tot<<" "<<maxm;
	return 0;
}