#include <bits/stdc++.h>
using namespace std;
int vis[11][11],len=0x3f3f3f3f,dirx[4]={0,0,1,-1},diry[4]={1,-1,0,0},mbx,mby,num[11][11],qdx,qdy;
struct node
{
	int leth,scx,scy;
};
void bfs()
{
	queue<node> q;
	q.push((node){0,qdx,qdy});
	while(!q.empty())
	{
		node x=q.front();
		q.pop();
		if(x.scx==mbx&&x.scy==mby)
		{
			len=min(len,x.leth);
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				int dx=dirx[i]+x.scx;
				int dy=diry[i]+x.scy;
				if(!vis[dx][dy]&&dx>=1&&dx<=10&&dy>=1&&dy<=10&&num[dx][dy])
				{
					vis[dx][dy]=1;
					q.push((node){x.leth+1,dx,dy});
				}
			}
		}
	}
}
int main ()
{
	string u;
	for(int i=1;i<=10;i++)
	{
		getline(cin,u);
		for(int j=0;j<u.size();j++)
		{
			if(u[j]=='.')
			num[i][j+1]=1;
			else if(u[j]=='L')
			{
				qdx=i;
				qdy=j+1;
				num[i][j+1]=1;
				vis[i][j+1]=1;
			}
			else if(u[j]=='R')
			{
				num[i][j+1]=0;
			}
			else
			{
				mbx=i;
				mby=j+1;
				num[i][j+1]=1;
			}
		}
	}
	bfs();
	cout<<len-1<<endl;
	return 0;
}