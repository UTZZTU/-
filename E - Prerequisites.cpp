#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200010];
int vis[200010],n,u,k;
vector<int> v;
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(int i=0;i<vec[x].size();i++)
	{
		dfs(vec[x][i]);
	}
	v.push_back(x);
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&u);
		for(int j=1;j<=u;j++)
		{
			scanf("%d",&k);
			vec[i].push_back(k);
		}
	}
	dfs(1);
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size()-1;i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}