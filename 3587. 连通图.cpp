#include <bits/stdc++.h>
using namespace std;
int n,m,fa[1010];
set<int> p;
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int main ()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
		fa[i]=i;
		p.clear();
		for(int i=1,x,y;i<=m;i++)
		{
			scanf("%d %d",&x,&y);
			int eu=find(x),ev=find(y);
			if(eu==ev)
			continue;
			fa[ev]=eu;
		}
		for(int i=1;i<=n;i++)
		if(fa[i]==i)
		p.insert(i);
		if(p.size()==1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}