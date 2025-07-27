#include <bits/stdc++.h>
using namespace std;
string s[210];
int n,m,vis[210][210],num[4],res,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
void bfs1(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int u=p.first,v=p.second;
		if(vis[u][v])
		{
			continue;
		}
		vis[u][v]=1;
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+u,yy=dy[i]+v;
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&s[xx][yy]=='.')
			{
				q.push({xx,yy});
			}
		}
	}
}
void bfs2(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int u=p.first,v=p.second;
		if(vis[u][v])
		{
			continue;
		}
		vis[u][v]=1;
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+u,yy=dy[i]+v;
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&s[xx][yy]=='#')
			{
				q.push({xx,yy});
			}
			else if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&s[xx][yy]=='.')
			{
				res++;
				bfs1(xx,yy);
			}
		}
	}
}
int main ()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		num[1]=num[2]=num[3]=0;
		getchar();
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		if(s[0][0]=='.')
		{
			bfs1(0,0);
		}
		else if(s[0][m-1]=='.')
		{
			bfs1(0,m-1);
		}
		else if(s[n-1][0]=='.')
		{
			bfs1(n-1,0);
		}
		else if(s[n-1][m-1]=='.')
		{
			bfs1(n-1,m-1);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!vis[i][j]&&s[i][j]=='#')
				{
					res=0;
					bfs2(i,j);
					if(res==0)
					{
						num[3]++;
					}
					else if(res==1)
					{
						num[1]++;
					}
					else if(res==2)
					{
						num[2]++;
					}
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			cout<<num[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}