#include <iostream>
using namespace std;
int ans=0;
int xy[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int visit[6][6];
bool check(int x,int y)
{
	if(x<0||x>5||y<0||y>5||visit[x][y]==1)
	return false;
	else
	return true;
}
void dfs(int x,int y,int l)
{
	if(l>12)
	return;
	if(x==0&&y==0&&l>0&&l<=12)
	{
		ans++;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int dx=xy[i][0]+x;
		int dy=xy[i][1]+y;
		if(check(dx,dy))
		{
			visit[dx][dy]=1;
			dfs(dx,dy,l+1);
			visit[dx][dy]=0;
		}
	}
}
int main ()
{
	dfs(0,0,0);
	cout<<ans-2;
	return 0;
}