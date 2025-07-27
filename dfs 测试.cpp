#include <iostream>
#include <deque>
using namespace std;
int visit[25][25]={0};
int north[25],west[25];
int bei[25],xi[25];
int n,gs=0;
int a[25][25];
int wz[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
deque<int> p;
bool check(int x,int y)
{
	if(x<1||x>n||y<1||y>n||visit[x][y]==1)
	return false;
	else
	return true;
}
void dfs(int x,int y)
{
	if(x==n&&y==n)
	{
		gs++;
		for(auto it=p.begin();it!=p.end();it++)
		{
			if(it!=p.begin())
			cout<<" ";
			cout<<*it;
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+wz[i][0],yy=y+wz[i][1];
		if(check(xx,yy))
		{
			p.push_back(a[xx][yy]);
			visit[xx][yy]=1;
			dfs(xx,yy);
			p.pop_back();
			visit[xx][yy]=0;
		}
	}
}
int main ()
{
	p.push_back(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		a[i][j]=ans++;
	}
	visit[1][1]=1;
	dfs(1,1);
	cout<<gs;
	return 0;
}