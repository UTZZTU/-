#include <iostream>
#include <deque>
using namespace std;
int visit[25][25]={0};
int north[25],west[25];
int bei[25],xi[25];
int n,zps=0;
int a[25][25];
int wz[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
deque<int> p;
bool check(int x,int y)
{
	if(x<1||x>n||y<1||y>n||visit[x][y]==1||bei[y]+1>north[y]||xi[x]+1>west[x])
	return false;
	else
	return true;
}
void dfs(int x,int y)
{
	if(zps==1)
	return;
	if(x==n&&y==n)
	{
		int pd=0;
		for(int i=1;i<=n;i++)
		{
			if(bei[i]!=north[i])
			{
				pd=1;
				break;
			}
		}
		if(pd==1)
		{
			return;
		}
		
			for(int i=1;i<=n;i++)
		{
			if(xi[i]!=west[i])
			{
				pd=1;
				break;
			}
		}
		if(pd==1)
		{
			return;
		}
		for(auto it=p.begin();it!=p.end();it++)
		{
			if(it!=p.begin())
			cout<<" ";
			cout<<*it;
			zps=1;
		}
		return;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+wz[i][0],yy=y+wz[i][1];
		if(check(xx,yy))
		{
			p.push_back(a[xx][yy]);
			visit[xx][yy]=1;
			bei[yy]++;
			xi[xx]++;
			dfs(xx,yy);
			p.pop_back();
			visit[xx][yy]=0;
			bei[yy]--;
			xi[xx]--;
		}
	}
}
int main ()
{
	visit[1][1]=1;
	bei[1]=1;
	xi[1]=1;
	p.push_back(0);
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		a[i][j]=ans++;
	}
	for(int i=1;i<=n;i++)
	cin>>north[i];
	for(int i=1;i<=n;i++)
	cin>>west[i];
	dfs(1,1);
	return 0;
}