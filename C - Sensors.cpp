#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int h,w,vis[1010][1010],res,dirx[8]={0,0,1,1,1,-1,-1,-1},diry[8]={1,-1,0,1,-1,0,1,-1};
string s[1010];
bool check(int dx,int dy)
{
	if(dx>=0&&dx<h&&dy>=0&&dy<w&&!vis[dx][dy]&&s[dx][dy]=='#') return true;
	return false;
}
void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int u=p.first,v=p.second;
		if(vis[u][v]) continue;
		vis[u][v]=1;
		for(int i=0;i<8;i++)
		{
			int dx=dirx[i]+u,dy=diry[i]+v;
			if(check(dx,dy))
			{
				q.push({dx,dy});
			}
		}
	}
}
int main ()
{
	scanf("%d%d",&h,&w);
	getchar();
	for(int i=0;i<h;i++) cin>>s[i];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(!vis[i][j]&&s[i][j]=='#')
			{
				bfs(i,j);
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}