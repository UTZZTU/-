#include<bits/stdc++.h>
using namespace std;
int n,d[20][20],dis[20];
bool flag[20];
int ans=-1;
void dfs(int dep,int sum)
{
	if(dep==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(ans>=sum+dis[n]-dis[dep-1])return;
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=1;
			dfs(dep+1,sum+d[dep][i]);
			flag[i]=0;
		}
	}
	return;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m=-1;
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
			m=max(m,d[i][j]);
		}
		dis[i]=dis[i-1]+m;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0; 
}