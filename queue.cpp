#include <iostream>
#include <string.h>
using namespace std;
int mn,t,ksx,ksy,jsx,jsy,bj,cs=0,scx,scy;
int a[8]={1,1,2,2,-1,-1,-2,-2};
int b[8]={2,-2,1,-1,2,-2,1,-1};
bool pd(int x,int y)
{
	if(x<0||x>=bj||y<0||y>=bj)
	return false;
	else
	return true;
}
void dfs(int x,int y)
{
	if(x==jsx&&y==jsy)
	{
		mn=min(mn,cs);
		return;
	}
	int i,j,dx,dy;
	for(i=0;i<8;i++)
	{
		dx=x+a[i];
		dy=y+b[i];
		if(pd(dx,dy)&&visit[dx][dy]==0)
		{
			cs++;
			dfs(dx,dy);
			cs--;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(visit,0,sizeof(visit));
		cs=0;
		mn=100000;
		cin>>bj;
		cin>>ksx>>ksy;
		cin>>jsx>>jsy;
		if(ksx==jsx&&ksy==jsy)
		printf("0\n");
		else
		{
			visit[ksx][ksy]=1;
			dfs(ksx,ksy);
			printf("%d\n",mn);
		}
	}
	return 0;
}