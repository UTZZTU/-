#include <bits/stdc++.h>
using namespace std;
string a[22];
int w,h,vis[22][22],ans,dirx[4]={0,0,-1,1},diry[4]={1,-1,0,0},x,y;
void bfs()
{
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int dx=dirx[i]+p.first,dy=diry[i]+p.second;
			if(dx>=0&&dx<h&&dy>=0&&dy<w&&!vis[dx][dy]&&a[dx][dy]=='.')
			{
				vis[dx][dy]=1;
				ans++;
				q.push({dx,dy});
			}
		}
	}
}
int main ()
{
	while(scanf("%d %d",&w,&h)!=EOF)
	{
		if(w==0&&h==0)
		break;
		memset(vis,0,sizeof(vis));
		ans=1,x=-1,y=-1;
		getchar();
		for(int i=0;i<h;i++)
		{
			cin>>a[i];
			if(x==-1&&y==-1)
			{
				for(int j=0;j<a[i].size();j++)
				{
					if(a[i][j]=='@')
					{
						x=i;
						y=j;
						break;
					}
				}
			}
		}
		vis[x][y]=1;
		bfs();
		cout<<ans<<endl;
	}
	return 0;
}