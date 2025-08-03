#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m,x,y,f[2010][2010],minn=0x3f3f3f3f,vis[2010][2010],dirx[4]={0,1,-1,0},diry[4]={1,0,0,-1};
string s[2010];
void bfs1()
{
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='@')
			{
				f[i][j]=0;
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		auto [u,v]=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int dx=dirx[i]+u,dy=diry[i]+v;
			if(dx>=0&&dx<n&&dy>=0&&dy<m&&(f[dx][dy]==-1||f[u][v]+1<f[dx][dy])&&s[dx][dy]!='#')
			{
				f[dx][dy]=f[u][v]+1;
				q.push({dx,dy});
			}
		}
	}
}
void bfs2()
{
	queue<pair<int,int>> q;
	vis[x][y]=0;
	q.push({x,y});
	while(!q.empty())
	{
		auto [u,v]=q.front();
		q.pop();
//		if(vis[u][v]!=-1) continue;
//		vis[u][v]=1;
		if(s[u][v]=='@')
		{
			if(f[2*x-u][2*y-v]!=-1)
			{
				minn=min(minn,vis[u][v]+f[2*x-u][2*y-v]);
//				cout<<u<<" "<<v<<endl;
//				cout<<f[u][v]<<endl;
			}
			
		}
		for(int i=0;i<4;i++)
		{
			int dx=dirx[i]+u,dy=diry[i]+v;
			if(dx>=0&&dx<n&&dy>=0&&dy<m&&(vis[dx][dy]==-1||vis[dx][dy]>vis[u][v]+1)&&s[dx][dy]!='#'&&2*x-dx>=0&&2*x-dx<n&&2*y-dy>=0&&2*y-dy<m&&s[2*x-dx][2*y-dy]!='#')
			{
				vis[dx][dy]=vis[u][v]+1;
				q.push({dx,dy});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>x>>y;
	x--,y--;
	memset(vis,-1,sizeof vis);
	memset(f,-1,sizeof f);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	bfs1();
	bfs2();
	if(minn>=6000000)
	cout<<-1<<endl;
	else cout<<minn<<endl;
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