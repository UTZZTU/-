#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
vector<int> vec[100010];
string s;
int n,u,v,res;
void dfs(int x,int pre)
{
	for(int i=0;i<vec[x].size();i++)
	{
		int j=vec[x][i];
		if(j==pre) continue;
		if(s[x]==s[j]) res++;
		dfs(j,x);
	}
}
void solve()
{
	cin>>n;
	cin>>s;
	s=' '+s;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,-1);
	cout<<res<<endl;
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