#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[101][10001],a,b,x,y,n;
void solve()
{
	cin>>n>>x>>y;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			f[i][j]=y+1;
		}
	}
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=i;j>=1;j--)
		{
			for(int k=x;k>=a;k--)
			{
				f[j][k]=min(f[j][k],f[j-1][k-a]+b);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			if(f[i][j]<=y) ans=max(ans,i+1);
		}
	}
	ans=min(ans,n);
	cout<<ans<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}	
	return 0;
}