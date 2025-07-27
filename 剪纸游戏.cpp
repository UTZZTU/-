#include <bits/stdc++.h>
using namespace std;
int n,m,res,sum;
string s[1010];
int vis[1010][1010];
int l,r,u,d,dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int uu=p.first,vv=p.second;
		if(vis[uu][vv]) continue;
		vis[uu][vv]=1;
		sum++;
		u=min(u,uu);
		d=max(d,uu);
		l=min(l,vv);
		r=max(r,vv);
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+uu,yy=dy[i]+vv;
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&s[xx][yy]=='.')
			{
				q.push({xx,yy});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='.'&&!vis[i][j])
			{
				sum=0;
				l=r=j;
				u=d=i;
				bfs(i,j);
				if((d-u+1)*(r-l+1)==sum) res++;
//				cout<<l<<" "<<r<<" "<<u<<" "<<d<<" "<<sum<<endl;
			}
		}
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}