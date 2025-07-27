#include <bits/stdc++.h>
using namespace std;
#define re register
#define il inline
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
}e[200020];
int fa[5005],n,m,k,ans,cnt,eu,ev;
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
	sort(e,e+m,cmp);
	for(re int i=0;i<m;i++)
	{
		eu=find(e[i].u);ev=find(e[i].v);
		if(eu==ev)
		continue;
		ans+=e[i].w;
		fa[ev]=eu;
		if(++cnt==n-k)
		break;
	}
	if(cnt<k-1)
	cout<<"No Answer";
	else
	cout<<ans;
}
int main ()
{
	n=read();m=read(),k=read();
	for(re int i=1;i<=n;i++)
	fa[i]=i;
	for(re int i=0;i<m;i++)
	e[i].u=read(),e[i].v=read(),e[i].w=read();
	kruskal();
	return 0;
}