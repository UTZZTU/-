#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,x[100],y[100],z[100],w[100],maxx;
void dfs(int level,int t1,int t2,int t3,int t4)
{
	maxx=max(maxx,t4);
	if(level>n)
	return;
	if(t1+x[level]<=a&&t2+y[level]<=b&&t3+z[level]<=c)
	dfs(level+1,t1+x[level],t2+y[level],t3+z[level],t4+w[level]);
	dfs(level+1,t1,t2,t3,t4);
}
int main ()
{
	cin>>n>>a>>b>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>z[i]>>w[i];
	}
	dfs(1,0,0,0,0);
	cout<<maxx;
	return 0;
}