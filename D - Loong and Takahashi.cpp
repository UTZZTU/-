#include <bits/stdc++.h>
using namespace std;
int n,f[50][50],cnt=1,x=1,y=1;
void solve()
{
	cin>>n;
	f[(n+1)/2][(n+1)/2]=-1;
	while(cnt<=n*n-1)
	{
		for(y;y<=n;y++)
		{
			if(f[x][y]==0)
			{
				f[x][y]=cnt++;
			}
			else break;
		}
		if(cnt==n*n) break;
//		cout<<x<<" "<<y<<endl;
		y--;
		x++;
		for(x;x<=n;x++)
		{
			if(f[x][y]==0)
			{
				f[x][y]=cnt++;
			}
			else break;
		}
		if(cnt==n*n) break;
//		cout<<x<<" "<<y<<endl;
		x--;
		y--;
		for(y;y>=1;y--)
		{
			if(f[x][y]==0)
			{
				f[x][y]=cnt++;
			}
			else break;
		}
		if(cnt==n*n) break;
//		cout<<x<<" "<<y<<endl;
		y++;
		x--;
		for(x;x>=1;x--)
		{
			if(f[x][y]==0)
			{
				f[x][y]=cnt++;
			}
			else break;
		}
		if(cnt==n*n) break;
		x++;
		y++;
//		cout<<x<<" "<<y<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]==-1) cout<<"T ";
			else cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
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