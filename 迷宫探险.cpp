#include <bits/stdc++.h>
using namespace std;
int minn=0x3f3f3f3f,vis[3010][3010],n,m,f[3010][3010],k,x,y,w,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0},cnt;
string s[3010];
struct node
{
	int x,y,cnt;
};
bool judge(int x,int y)
{
	if(x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&s[x][y]!='#') return true;
	return false;
}
void bfs()
{
	queue<node> q;
	q.push({0,0,0});
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		x=p.x,y=p.y,cnt=p.cnt;
		if(vis[x][y]||s[x][y]=='#') continue;
		vis[x][y]=1;
		if(x==n-1&&y==m-1) 
		{
			minn=min(minn,cnt);
			return;
		}
		if(s[x][y]=='*')
		{
			for(int i=0;i<4;i++)
			{
				int xx=dirx[i]*f[x+1][y+1]+x,yy=diry[i]*f[x+1][y+1]+y;
				if(judge(xx,yy))
				{
					q.push({xx,yy,cnt});
				}
			}
		}
		else if(s[x][y]=='.')
		{
			for(int i=0;i<4;i++)
			{
				int xx=dirx[i]+x,yy=diry[i]+y;
				if(judge(xx,yy))
				{
					q.push({xx,yy,cnt+1});
				}
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
	cin>>k;
	while(k--)
	{
		cin>>x>>y>>w;
		f[x][y]=w;
	}
	bfs();
	if(minn==0x3f3f3f3f) printf("-1");
	else printf("%d",minn);
	return 0;
}