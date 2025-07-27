#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n,m,res,vis[210][210][4],dirx[4]={0,0,1,-1},diry[4]={-1,1,0,0};
string s[210];
set<pair<int,int>> st;
struct node
{
	int x,y,pos;
};
bool check(int x,int y,int k)
{
	if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y][k]&&s[x][y]=='.') return true;
	return false;
}
void bfs()
{
	queue<node> q;
	q.push({1,1,-1});
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		int x=p.x,y=p.y;
		if(p.pos==-1)
		{
			vis[x][y][0]=vis[x][y][1]=vis[x][y][2]=vis[x][y][3]=1;
			st.insert({x,y});
			for(int i=0;i<4;i++)
			{
				int dx=dirx[i]+x,dy=diry[i]+y;
				if(check(dx,dy,i)) q.push({dx,dy,i});
			}
			continue;
		}
		
		if(vis[x][y][p.pos]) continue;
		
		vis[x][y][p.pos]=1;
		st.insert({x,y});
		
			int dx=dirx[p.pos]+x,dy=diry[p.pos]+y;
			if(check(dx,dy,p.pos)) q.push({dx,dy,p.pos});
			else if(s[dx][dy]=='#')
			{
				for(int i=0;i<4;i++)
				{
					dx=dirx[i]+x,dy=diry[i]+y;
					if(check(dx,dy,i)) q.push({dx,dy,i});
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
	bfs();
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			if(s[i][j]=='#') cout<<"#";
//			else if(vis[i][j]) cout<<"1";
//			else cout<<".";
//		}
//		cout<<endl;
//	}
	cout<<st.size();
	return 0;
}