#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m,sx,sy,ex,ey,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0},h[1010],l[1010];
int vis[1010][1010];
struct node
{
	int x,y;
};
string s[1010];
void bfs1()
{
	queue<node> q;
	q.push({ex,ey});
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
		if(vis[u.x][u.y]) continue;
		vis[u.x][u.y]=1;
		h[u.x]=1;
		l[u.y]=1;
		for(int i=0;i<4;i++)
		{
			int xx=dirx[i]+u.x,yy=diry[i]+u.y;
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&s[xx][yy]=='.')
			{
				q.push({xx,yy});
			}
		}
	}
}
void bfs2()
{
	queue<node> q;
	q.push({sx,sy});
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
		if(vis[u.x][u.y]) continue;
		vis[u.x][u.y]=1;
		for(int i=0;i<4;i++)
		{
			int xx=dirx[i]+u.x,yy=diry[i]+u.y;
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy])
			{
				if(s[xx][yy]=='.')
				q.push({xx,yy});
				else
				{
					if(xx==u.x&&h[xx]||yy==u.y&&l[yy]||(u.x-1>=0&&h[u.x-1])||(u.x+1<n&&h[u.x+1])||(u.y-1>=0&&l[u.y-1])||(u.y+1<m&&l[u.y+1]))
					{
//						cout<<"pp"<<endl;
//						cout<<xx<<" "<<yy<<endl;
						vis[ex][ey]=1;
						return;
					}
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
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			else if(s[i][j]=='E')
			{
				ex=i;
				ey=j;
			}
		}
	}
	bfs1();
	memset(vis,0,sizeof vis);
	bfs2();
	if(vis[ex][ey]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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