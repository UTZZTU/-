#include <bits/stdc++.h>
using namespace std;
int fa[10010];
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int qz[10010],tot;
int main ()
{
	int n;
	cin>>n;
	for(int i=1,k,s;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&s);
			if(!fa[s])
			fa[s]=s;
			if(!qz[i])
			qz[i]=s;
			else
			{
				int eu=find(qz[i]),ev=find(s);
				fa[ev]=eu;
			}
		}
	}
	set<int> p;
	for(int i=1;i<=10000;i++)
	{
		if(fa[i])
		tot++;
		if(fa[i]==i)
		p.insert(i);
	}
	cout<<tot<<" "<<p.size()<<endl;
	int k;
	cin>>k;
	for(int i=1,x,y;i<=k;i++)
	{
		scanf("%d %d",&x,&y);
		if(find(x)==find(y))
		cout<<"Y"<<endl;
		else
		cout<<"N"<<endl;
	}
	return 0;
}