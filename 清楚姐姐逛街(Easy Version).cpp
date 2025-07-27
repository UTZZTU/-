#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
string mp[810];
int n,m,xs,ys,q,xt,yt,vis[810][810],num[810][810],minn,dirx[4]={0,0,1,-1},diry[4]={1,-1,0,0},pos[810][810];
void dfs(int x,int y,int tt)
{
	if(mp[x][y]=='.')
	{
		num[x][y]=INF+tt;
		if(pos[x][y])
		minn=min(minn,max(tt,pos[x][y]));
		return;
	}
	num[x][y]=tt;
	if(mp[x][y]=='L')
	{
		if(mp[x][y-1]=='#')
		{
			num[x][y]=INF+tt;
			if(pos[x][y])
			minn=min(minn,max(tt,pos[x][y]));
			return;
		}
		else
		{
			if(pos[x][y]&&tt>=pos[x][y])
			{
				minn=min(minn,tt);
				return;
			}
			dfs(x,y-1,tt+1);
		}
	}else if(mp[x][y]=='R')
	{
		if(mp[x][y+1]=='#')
		{
			num[x][y]=INF+tt;
			if(pos[x][y])
			minn=min(minn,max(tt,pos[x][y]));
			return;
		}
		else
		{
			if(pos[x][y]&&tt>=pos[x][y])
			{
				minn=min(minn,tt);
				return;
			}
			dfs(x,y+1,tt+1);
		}
	}else if(mp[x][y]=='U')
	{
		if(mp[x-1][y]=='#')
		{
			num[x][y]=INF+tt;
			if(pos[x][y])
			minn=min(minn,max(tt,pos[x][y]));
			return;
		}
		else
		{
			if(pos[x][y]&&tt>=pos[x][y])
			{
				minn=min(minn,tt);
				return;
			}
			dfs(x-1,y,tt+1);
		}
	}else if(mp[x][y]=='D')
	{
		if(mp[x+1][y]=='#')
		{
			num[x][y]=INF+tt;
			if(pos[x][y])
			minn=min(minn,max(tt,pos[x][y]));
			return;
		}
		else
		{
			if(pos[x][y]&&tt>=pos[x][y])
			{
				minn=min(minn,tt);
				return;
			}
			dfs(x+1,y,tt+1);
		}
	}
}
void bfs(int x,int y,int tt)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	bool flag=false;
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int dx=p.first,dy=p.second;
		if(vis[dx][dy])
		continue;
		vis[dx][dy]=1;
		if(!flag)
		{
			pos[dx][dy]=tt;
			flag=true;
		}
		for(int i=0;i<4;i++)
		{
			if(vis[dx+dirx[i]][dy+diry[i]]||mp[dx+dirx[i]][dy+diry[i]]=='#')
			continue;
			pos[dx+dirx[i]][dy+diry[i]]=pos[dx][dy]+1;
			q.push({dx+dirx[i],dy+diry[i]});
		}
	}
}
int main ()
{
	cin>>n>>m>>xs>>ys>>q;
	getchar();
	for(int i=0;i<n;i++)
	cin>>mp[i];
	bfs(xs,ys,1);
	while(q--)
	{
		cin>>xt>>yt;
		minn=INF;
		dfs(xt,yt,1);
		if(minn==INF)
		cout<<-1<<endl;
		else
		cout<<minn-1<<endl;
	}
	return 0;
}