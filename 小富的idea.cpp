#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,v;
}s[101000];
int n,q,t,f[101000],tt[101000],mb,fa[101000],cnt;
int get_ti(int x,int y)
{
	int dis=(s[x].x-s[y].x)*(s[x].x-s[y].x)+(s[x].y-s[y].y)*(s[x].y-s[y].y);
	if(s[x].v+s[y].v==0) return 0x3f3f3f3f;
	return ceil(sqrt(dis)*1.0/(s[x].v+s[y].v));
}
struct link{
	int x,y,dist;
}p[1000010];
bool cmp(link a,link b)
{
	return a.dist<b.dist;
}
int find(int x)
{
	while(x!=fa[x])  x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	scanf("%d",&n);
	f[0]=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].v);
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			p[++cnt]={i,j,get_ti(i,j)};
		}
	}
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int eu=find(p[i].x),ev=find(p[i].y);
		if(eu!=ev)
		{
			fa[eu]=ev;
            if(p[i].dist<=1000)
			f[p[i].dist]--;
		}
	}
	int res=0;
	for(int i=0;i<=1000;i++)
	{
		res+=f[i];
		tt[i]=res;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&t);
		printf("%d\n",tt[t]);
	}
	return 0;
} 