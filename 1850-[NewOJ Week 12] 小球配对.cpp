#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,fa[200010],num[200010],vis[200010],res;
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		int eu=find(x),ev=find(y);
		if(eu!=ev)
		{
			fa[ev]=eu;
			num[eu]+=num[ev]+1;
		}
		else num[eu]++;
	}
	for(int i=1;i<=m;i++)
	{
		int eu=find(i);
		if(!vis[eu])
		{
			vis[eu]=1;
			if(num[eu]&1) res++;
		}
	}
	cout<<res;
	return 0;
}