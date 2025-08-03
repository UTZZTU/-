#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,vis[1010][1010][5][2],dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0};
string s[1010];
struct node
{
	int x,y,cnt;
	int fx;
	int flag;
};
void bfs()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k1=0;k1<=4;k1++)
			{
				for(int k2=0;k2<=1;k2++)
				{
					vis[i][j][k1][k2]=0x3f3f3f3f;
				}
			}
		}
	}
	queue<node> q;
	q.push({0,0,0,0,0});
	q.push({0,0,0,1,0});
	q.push({0,0,0,2,0});
	q.push({0,0,0,3,0});
	q.push({0,0,0,4,1});
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
//		cout<<u.x<<" "<<u.y<<" "<<u.cnt<<" "<<u.flag<<" "<<u.fl<<endl;
		if(vis[u.x][u.y][u.fx][u.flag]<=u.cnt) continue;
		else vis[u.x][u.y][u.fx][u.flag]=u.cnt;
		for(int i=0;i<4;i++)
		{
			if(u.fx==i) continue;
			int xx=dirx[i]+u.x,yy=diry[i]+u.y;
			if(xx>=0&&xx<n&&yy>=0&&yy<m)
			{
				if(s[xx][yy]=='X')
				{
					if(u.flag==0)
					q.push({xx,yy,u.cnt+1,u.fx,1});
				}
				else
				{
					q.push({xx,yy,u.cnt+1,u.fx,u.flag});
				}
			}
		}
		
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	bfs();
	int pp=0x3f3f3f3f;
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=1;j++)
		{
			pp=min(pp,vis[n-1][m-1][i][j]);
		}
	}
	if(pp>=2000000) cout<<-1<<endl;
	else
	cout<<pp<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}