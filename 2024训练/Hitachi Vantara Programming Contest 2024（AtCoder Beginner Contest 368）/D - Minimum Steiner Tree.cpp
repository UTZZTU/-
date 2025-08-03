#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
vector<int> vec[200010];
int n,k,a,b,vis[200010],pos;
int dfs(int x,int pre)
{
	int sum=0;
	for(int i=0;i<vec[x].size();i++)
	{
		int j=vec[x][i];
		if(j==pre) continue;
		sum+=dfs(j,x);
	}
	if(sum)
	{
		return sum+1;
	}
	else if(vis[x]) return 1;
	else return 0;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for(int i=1;i<=k;i++)
	{
		int p;
		cin>>p;
		if(i==1) pos=p;
		vis[p]=1;
	}
	cout<<dfs(pos,-1);
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