#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int t,n;
set<int> p;
set<int> q[1010];
void dfs(int x,int ans)
{
	if(x>n)
	{
		p.insert(ans);
		return;
	}
	for(auto it=q[x].begin();it!=q[x].end();it++)
	{
		dfs(x+1,ans+*it);
	}
}
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		p.clear();
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int j=1,x;j<=n;j++)
		{
			scanf("%d",&x);
			for(int k=1;k<=x;k++)
			{
				scanf("%d",&a[x][k]);
				q[x].insert((int)log(a[x][k]));
			}
		}
		dfs(2,log(a[1][1]));
		cout<<p.size()<<endl;
		for(int j=1;j<=n;j++)
		q[j].clear();
	}
	return 0;
}