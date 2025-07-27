#include <bits/stdc++.h>
using namespace std;
string u,v;
bool vis[30][30];
int n,m,num;
void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty())
	{
		
		pair<int,int> p=q.front();
		q.pop();
		if(p.first<1||p.first>n||p.second<1||p.second>m||vis[p.first][p.second])
		continue;
		num++;
		vis[p.first][p.second]=1;
		if(u[p.first-1]=='<')
		q.push({p.first,p.second-1});
		else
		q.push({p.first,p.second+1});
		if(v[p.second-1]=='v')
		q.push({p.first+1,p.second});
		else
		q.push({p.first-1,p.second});
	}
}
int main ()
{
	cin>>n>>m;
	getchar();
	cin>>u;
	cin>>v;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			memset(vis,0,sizeof(vis));
			num=0;
			bfs(i,j);
			if(num!=n*m)
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}