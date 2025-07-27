#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
int n,color[1000010],black,white,u,v;
vector<int> vec[1000010];
void dfs(int x)
{
	for(int i=0;i<vec[x].size();i++)
	{
		int j=vec[x][i];
		if(color[j]==-1)
		{
			color[j]=1-color[x];
			if(color[j]==0) black++;
			else white++;
			dfs(j);
		}
	}
}
int main ()
{
	memset(color,-1,sizeof color);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	color[1]=0;
	black=1;
	dfs(1);
	cout<<(ll)black*white-(n-1);
	return 0;
}