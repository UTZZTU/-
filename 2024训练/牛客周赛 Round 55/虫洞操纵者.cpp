#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[1010][1010],n,f[1010][1010],dirx[4]={-1,0,0,1},diry[4]={0,1,-1,0};
struct node
{
	int x,y,cnt;
};
void bfs()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vis[i][j]=0x3f3f3f3f;
		}
	}
	queue<node> q;
	q.push({1,1,0});
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
		int x=u.x,y=u.y,cnt=u.cnt;
		if(cnt>=vis[x][y]) continue;
		else
		vis[x][y]=cnt;
		for(int i=0;i<4;i++)
		{
			int xx=x+dirx[i],yy=y+diry[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=n)
			{
				if(f[xx][yy]==0)
				{
					if(cnt+1<vis[xx][yy])
					{
						q.push({xx,yy,cnt+1});
					}
				}
				else
				{
					int posx=x,posy=y;
					while(1)
					{
						posx+=dirx[3-i],posy+=diry[3-i];
						if(posx<=0||posx>n||posy<=0||posy>n||f[posx][posy]==1)
						{
							posx-=dirx[3-i],posy-=diry[3-i];
							break;
						}
					}
					if(cnt+1<vis[posx][posy])
					{
						q.push({posx,posy,cnt+1});
					}
				}
			}
			else
			{
				int posx=x,posy=y;
				while(1)
				{
					posx+=dirx[3-i],posy+=diry[3-i];
					if(posx<=0||posx>n||posy<=0||posy>n||f[posx][posy]==1)
					{
						posx-=dirx[3-i],posy-=diry[3-i];
						break;
					}
				}
				if(cnt+1<vis[posx][posy])
				{
					q.push({posx,posy,cnt+1});
				}
			}
			
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>f[i][j];
		}
	}
	bfs();
	if(vis[n][n]>=10000000) cout<<"-1"<<endl;
	else cout<<vis[n][n]<<endl;
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