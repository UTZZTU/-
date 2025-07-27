#include <bits/stdc++.h>
using namespace std;
#define il inline
int fa[1010];
int find(int x)
{
	while(x!=fa[x]) x=fa[x];
	return x;
}
int G[1010];
int mp[1010];
int main ()
{
	int n,tot=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int m,x;
		scanf("%d:",&m);
		for(int j=1;j<=m;j++)
		{
			int eu,ev;
			scanf("%d",&x);
			if(G[x]==0)
			G[x]=i;
			eu=find(G[x]);
			ev=find(i);
			if(eu!=ev)
			fa[eu]=ev;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int f=find(i);
		if(mp[f]==0)
		tot++;
		mp[f]++;
	}
	sort(mp+1,mp+1+n);
	cout<<tot<<endl;
	for(int i=n;mp[i]>0;i--)
	{
		if(i!=n)
		cout<<" ";
		cout<<mp[i];
	}
	return 0;
}