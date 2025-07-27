#include <iostream>
using namespace std;
struct point
{
	int x,y;
}now;
int ans;
bool path[8][8]={0};
int moved[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
void dfs()
{
	if(now.x+now.y==7)
	{
		ans++;
		return;
	}
	for(int j=0;j<4;j++)
	{
		if(j==1&&now.y-1<=0)
		continue;
		if(j==3&&now.x-1<=0)
		continue;
		if(path[now.x+moved[j][0]][now.y+moved[j][1]]==1)
		continue;
		now.x+=moved[j][0];
        now.y+=moved[j][1];
        path[now.x][now.y]=1;
        dfs();
        path[now.x][now.y]=0;
        now.x-=moved[j][0];
        now.y-=moved[j][1];
	}
}
int main ()
{
	now.x=now.y=0;
	dfs();
	cout<<ans;
	return 0;
}