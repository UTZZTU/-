#include <bits/stdc++.h>
using namespace std;
int maxx,n,m;
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)
	return true;
	else
	return false;
}
string a[1010];
void dfs(int x,int y,int js,int fx)
{
	if(!check(x,y))
	{
		maxx=max(maxx,js);
		return;
	}
	js++;
	if(fx==1)
	{
		if(a[x][y]=='/')
			dfs(x-1,y,js,4);
		else
			bj=2;
			dfs(x+1,y,js,2);
	}
	else if(fx==2)
	{
		if(a[x][y]=='/')
		dfs(x,y-1,js,3);
		else
		dfs(x,y+1,js,1);
	}
	else if(fx==3)
	{
		if(a[x][y]=='/')
		dfs(x+1,y,js,2);
		else
		dfs(x-1,y,js,4);
	}
	else if(fx==4)
	{
		if(a[x][y]=='/')
		dfs(x,y+1,js,1);
		else
		dfs(x,y-1,js,3);
	}
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	getline(cin,a[i]);
	for(int i=0;i<n;i++)
	{
		dfs(i,0,0,1);
		dfs(i,m-1,0,3);
	}
	for(int i=0;i<m;i++)
	{
		dfs(0,i,0,2);
		dfs(n-1,i,0,4);
	}
	cout<<maxx;
	return 0;
}