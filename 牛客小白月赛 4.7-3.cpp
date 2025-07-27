#include <bits/stdc++.h>
using namespace std;
int n,m,rootx,rooty,res,vis[1010][1010],dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
string s[1010];
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&s[x][y]!='#')
	return true;
	return false;
}
void bfs()
{
	queue<pair<int,int>> q;
	q.push({rootx,rooty});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int ddx=p.first,ddy=p.second;
		if(vis[ddx][ddy]) continue;
		vis[ddx][ddy]=1;
		if(s[ddx][ddy]=='!') res++;
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+ddx,yy=dy[i]+ddy;
			if(check(xx,yy))
			q.push({xx,yy});
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
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='@')
			{
				rootx=i;
				rooty=j;
			}
		}
	}
	bfs();
	cout<<res;
	return 0;
}