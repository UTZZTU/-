#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Mul(a) ((long long)(a) * (a))
pair<int,int> a[100010];
int last[11],cnt,fa[100010],n;
struct node
{
	int u,v,w;
}s[2200010];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
void add(int x,int y)
{	cnt++;
	s[cnt].u=x;
	s[cnt].v=y;
	s[cnt].w=Mul(a[x].first-a[y].first)+Mul(a[x].second-a[y].second);
//	cout<<x<<" "<<y<<endl;
}
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
void kruskal()
{
	int res=0;
	sort(s+1,s+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
//		cout<<s[i].w<<endl;
		int eu=find(s[i].u),ev=find(s[i].v);
		if(eu!=ev)
		{
			res+=s[i].w;
			fa[ev]=eu;
		}
	}
	cout<<res;
}
signed main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
//		cout<<a[i].first<<" "<<a[i].second;
		fa[i]=i;
	}
	
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)
//	{
//		
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=10;j++)
		{
			if(last[j]) add(i,last[j]);
		}
		last[a[i].second]=i;
	}
	kruskal();
	return 0;
}