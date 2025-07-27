#include <bits/stdc++.h>
using namespace std;
int n,w,f[20],p[20],minn=100;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int level, int cnt)
{
	if(level>n)
	{
		minn=min(minn,cnt);
		return;
	}
	if(cnt>minn) return;
	for(int i=1;i<=cnt;i++)
	{
		if(f[level]+p[i]<=w)
		{
			p[i]+=f[level];
			dfs(level+1,cnt);
			p[i]-=f[level];
		}
	}
	
	p[cnt+1]=f[level];
	dfs(level+1,cnt+1);
	p[cnt+1]=0;
}
int main ()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+n,cmp);
	p[1]=f[1];
	dfs(2,1);
	cout<<minn;
	return 0;
}