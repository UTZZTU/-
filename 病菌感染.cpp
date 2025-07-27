#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0},f[1010][1010],n,m,ans;
bool check(int x,int y)
{
	int sum=0;
	if(x<1||x>n||y<1||y>n||f[x][y])
	return false;
	sum+=f[x-1][y]+f[x+1][y]+f[x][y+1]+f[x][y-1];
	return sum>=2;
}
struct node
{
	int x,y;
};
queue<node> q;
void solve()
{
	while(!q.empty())
	{
		node x=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=dx[i]+x.x,ny=dy[i]+x.y;
			if(check(nx,ny))
			{
				f[nx][ny]=1;
				ans++;
				q.push({nx,ny});
			}
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ans=m;
	for(int i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		q.push({x,y});
		f[x][y]=1;
	}
	solve();
	if(ans==n*n)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}