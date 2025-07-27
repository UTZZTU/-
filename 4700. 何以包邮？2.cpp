#include <bits/stdc++.h>
using namespace std;
int n,x,f[110],minn=0x3f3f3f3f;
void dfs(int level,int res)
{
	if(level>n+1)
	return;
	if(res>=x)
	{
		minn=min(minn,res);
		return;
	}
	if(res>=minn)
	{
		return;
	}
	dfs(level+1,res+f[level]);
	dfs(level+1,res);
}
int main ()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	dfs(1,0);
	cout<<minn;
	return 0;
}