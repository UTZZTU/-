#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
#define il inline
#define re register
int monkey[1010];
il int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
struct node
{
	int x,y;
}s[101000];
struct Edge
{
	int u,v;
	double w;
}e[maxn];
int cnt,fa[5050],n,m,eu,ev,tot;
double maxm;
il void add(int u,int v,double w)
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
	sort(e+1,e+1+cnt,cmp);
	for(re int i=1;i<=cnt;i++)
	{
		eu=find(e[i].u);ev=find(e[i].v);
		if(eu==ev)
		continue;
		if(e[i].w>maxm)
		maxm=e[i].w;
		fa[ev]=eu;
		if(++tot==m-1)
		break;
	}
}
int main ()
{
	int sum=0;
	n=read();
	for(re int i=1;i<=n;i++)
	monkey[i]=read();
	m=read();
	for(re int i=1;i<=m;i++)
	fa[i]=i;
	for(re int i=1,x,y;i<=m;i++)
	{
		x=read();y=read();
		s[i].x=x;
		s[i].y=y;
	}
	for(re int i=1;i<m;i++)
	{
		for(re int j=i+1;j<=m;j++)
		{
			double w=sqrt((s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y));
			add(i,j,w);
		}
	}
	kruskal();
	for(re int i=1;i<=n;i++)
	if(monkey[i]>=maxm)
	sum++;
	printf("%d",sum);
	return 0;
}