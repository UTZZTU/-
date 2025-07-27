#include <bits/stdc++.h>
using namespace std;
int fa[110],g[110][110];
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int n,m,k;
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x][y]=z;
		g[y][x]=z;
		if(z==1)
		{
		    int eu=find(x),ev=find(y);
		    if(eu!=ev)
		    fa[ev]=eu;
		}
	}
	for(int i=1,x,y;i<=k;i++)
	{
		cin>>x>>y;
		if(g[x][y]==1||g[x][y]==0&&find(x)==find(y))
		cout<<"No problem"<<endl;
		else if(g[x][y]==0&&find(x)!=find(y))
		cout<<"OK"<<endl;
		else if(g[x][y]==-1&&find(x)==find(y))
		cout<<"OK but..."<<endl;
		else if(g[x][y]==-1&&find(x)!=find(y))
		cout<<"No way"<<endl;
	}
	return 0;
}