#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fa[2010],sum,a[2010],cnt;
ll ans;
inline int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
int Find(int x)
{
	while(x!=fa[x])x=fa[x];
	return x;
}
struct edge
{
	int u,v,w;
}e[2000000];
inline bool cmp(edge a,edge b)
{
	return a.w>b.w;
}
int main ()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		fa[i]=i;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			e[++sum].u=i;e[sum].v=j;e[sum].w=a[i]^a[j];
		}
	}
	sort(e+1,e+sum+1,cmp);
	for(int i=1,u,v;i<=sum;i++)
	{
		u=e[i].u;v=e[i].v;
		if(Find(u)==Find(v))
		continue;
		ans+=e[i].w;
		fa[Find(u)]=Find(v);
		cnt++;
		if(cnt==n-1)
		break;
	}
	cout<<ans;
	return 0;
}