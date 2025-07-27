#include <bits/stdc++.h>
using namespace std;
int n,m,q,f[10000010],vis[3010][3010],cnt=1,dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
string s[3010];
bool check(int x,int y,int num)
{
	if(num==1)
	{
		if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&s[x][y]=='-')
		return true;
		return false;
	}
	else
	{
		if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&s[x][y]=='+')
		return true;
		return false;
	}
}
int bfs(int x,int y,int pos)
{
	int res=0;
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		int ddx=p.first,ddy=p.second;
		q.pop();
		if(vis[ddx][ddy]) continue;
		vis[ddx][ddy]=pos;
		res++;
		for(int i=0;i<4;i++)
		{
			int xx=ddx+dx[i],yy=ddy+dy[i];
			if(s[ddx][ddy]=='+')
			{
				if(check(xx,yy,1))
				q.push({xx,yy});
			}
			else
			{
				if(check(xx,yy,-1))
				q.push({xx,yy});
			}
		}
	}
	return res;
}
int main ()
{
	scanf("%d%d%d",&n,&m,&q);
	getchar();
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			if(vis[i][j]) continue;
			f[cnt]=bfs(i,j,cnt);
			cnt++;
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<vis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",f[vis[x-1][y-1]]);
	}
	return 0;
}