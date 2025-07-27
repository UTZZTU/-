#include <bits/stdc++.h>
using namespace std;
int n,m,dist[110][110],rootx,rooty,mbx,mby,vis[110][110],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
string s[110];
void search()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='S') rootx=i,rooty=j;
			else if(s[i][j]=='E') mbx=i,mby=j;
		}
	}
}
bool judge(int x,int y)
{
	if(s[x][y]=='*'||x-1>=0&&s[x-1][y]=='*'||x+1<n&&s[x+1][y]=='*'||y-1>=0&&s[x][y-1]=='*'||y+1<m&&s[x][y+1]=='*'||x-1>=0&&y-1>=0&&s[x-1][y-1]=='*'||x+1<n&&y-1>=0&&s[x+1][y-1]=='*'||x-1>=0&&y+1<m&&s[x-1][y+1]=='*'||x+1<n&&y+1<m&&s[x+1][y+1]=='*')
	return true;
	return false;
}
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&!judge(x,y))
	return true;
	return false;
}
struct node
{
	int fi,se,x;
};
void bfs()
{
	queue<node> q;
	q.push({rootx,rooty,1});
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		if(vis[p.fi][p.se]) continue;
		vis[p.fi][p.se]=1,dist[p.fi][p.se]=p.x;
		if(p.fi==mbx&&p.se==mby) return;
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+p.fi,yy=dy[i]+p.se;
			if(check(xx,yy))
			{
				q.push({xx,yy,p.x+1});
			}
		}
	}
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	search();
	bfs();
	if(dist[mbx][mby]==0)
	cout<<"Impossible";
	else
	cout<<dist[mbx][mby]-1;
	return 0;
}