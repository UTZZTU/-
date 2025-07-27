#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <string.h>
using namespace std;
int t,m,n,x1,y1,x2,y2,k,dirx[4]={0,0,-1,1},diry[4]={1,-1,0,0},maxx[110][110],tot;
string a[110];
bool check(int x,int y)
{
	if(x<0||x>=m||y<0||y>=n||a[x][y]=='*')
	return false;
	else
	return true;
}
bool dfs(int x,int y,int pos,int ans)
{
	if(x==x2&&y==y2)
	return true;
	for(int i=0;i<4;i++)
	{
		int dx=dirx[i]+x,dy=diry[i]+y;
		if(check(dx,dy))
		{
		tot=i==pos?0:1;
		if(ans+tot>k||ans+tot>maxx[dx][dy])
		continue;
		maxx[dx][dy]=ans+tot;
		if(dfs(dx,dy,i,ans+tot))
		return true;
		}
	}
	return false;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
    {
    	scanf("%d %d",&m,&n);
    	getchar();
    	for(int i=0;i<m;i++)
    	cin>>a[i];
    	memset(maxx,0x3f3f3f3f,sizeof(maxx));
    	scanf("%d %d %d %d %d",&k,&y1,&x1,&y2,&x2);
    	x1--,x2--,y1--,y2--;
    	maxx[x1][y1]=0;
    	if(dfs(x1,y1,-1,-1))
    	cout<<"yes"<<endl;
    	else
    	cout<<"no"<<endl;
	}
	return 0;
}