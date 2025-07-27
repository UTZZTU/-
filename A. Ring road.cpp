#include <bits/stdc++.h>
using namespace std;
int f1[110][110],f2[110][110];
int n,a,b,c,res,pp;
vector<int> vec[110];
int vis[110];
void dfs(int x)
{
	vis[x]=1;
	if(!vis[vec[x][0]])
	{
		if(f1[x][vec[x][0]]==-1) pp+=f2[x][vec[x][0]];
		dfs(vec[x][0]);
	}
	else if(!vis[vec[x][1]])
	{
		if(f1[x][vec[x][1]]==-1) pp+=f2[x][vec[x][1]];
		dfs(vec[x][1]);
	}
	else
	{
		if(f1[x][1]==-1) pp+=f2[x][1];
		return;
	}
	return;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		res+=c;
		f2[a][b]=c;
		f2[b][a]=c;
		f1[a][b]=1;
		f1[b][a]=-1;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1);
	cout<<min(pp,res-pp);
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