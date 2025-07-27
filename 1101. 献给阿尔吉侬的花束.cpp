#include <bits/stdc++.h>
using namespace std;
int vis[210][210],r,c,t,sx,sy,ex,ey,judge,l,dirx[4]={0,0,1,-1},diry[4]={1,-1,0,0};
string a[210];
struct node
{
	int x,y,ans;
};
void bfs()
{
	queue<node> q;
	q.push({sx,sy,0});
	vis[sx][sy]=1;
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		if(u.x==ex&&u.y==ey)
		{
			judge=1;
			l=u.ans;
			break;
		}
		for(int i=0;i<4;i++)
		{
			int dx=dirx[i]+u.x,dy=diry[i]+u.y;
			if(dx<0||dx>=r||dy<0||dy>=c||vis[dx][dy]||a[dx][dy]=='#')
			continue;
			vis[dx][dy]=1;
			q.push({dx,dy,u.ans+1});
		}
	}
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		judge=0;
		memset(vis,0,sizeof(vis));
		scanf("%d %d",&r,&c);
		getchar();
		for(int i=0;i<r;i++)
		cin>>a[i];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(a[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				if(a[i][j]=='E')
				{
					ex=i;
					ey=j;
				}
			}
		}
		bfs();
		if(judge)
		cout<<l<<endl;
		else
		cout<<"oop!"<<endl;
	}
	return 0;
}