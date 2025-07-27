#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <string.h>
using namespace std;
int t,m,n,vis[110][110],x1,y1,x2,y2,k,judge,dirx[4]={0,0,-1,1},diry[4]={1,-1,0,0};
string a[110];
bool check(int x,int y)
{
	if(x<0||x>=m||y<0||y>=n||vis[x][y]||a[x][y]=='*')
	return false;
	else
	return true;
}
void dfs(int x,int y,int pos,int ans)
{
	if(judge)
	return;
	if(x==x2&&y==y2)
	{
		if(ans<=k)
		judge=1;
		return;
	}
	if(ans>k)
	return;
	for(int i=0;i<4;i++)
	{
		int dx=dirx[i]+x,dy=diry[i]+y;
		if(check(dx,dy))
		{
			vis[dx][dy]=1;
			if(pos==-1)
			dfs(dx,dy,i,ans);
			else
			{
			   if(i!=pos)
			   dfs(dx,dy,i,ans+1);
			   else
			   dfs(dx,dy,i,ans);
			}
			vis[dx][dy]=0;
		}
	}
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
    	memset(vis,0,sizeof(vis));
    	scanf("%d %d %d %d %d",&k,&y1,&x1,&y2,&x2);
    	x1--,x2--,y1--,y2--;
    	judge=0;
    	vis[x1][y1]=1;
    	dfs(x1,y1,-1,0);
    	if(judge)
    	cout<<"yes"<<endl;
    	else
    	cout<<"no"<<endl;
	}
	return 0;
}