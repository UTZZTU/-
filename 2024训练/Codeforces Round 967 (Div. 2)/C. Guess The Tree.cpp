#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
vector<pair<int,int>> vec;
int n;
int ask(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	return x;
}
void dfs(int x,map<int,vector<int>> mp)
{
	for(int i=0;i<mp[x].size();i++)
	{
		int j=mp[x][i];
		int p=ask(x,j);
		if(p==x)
		vec.push_back({x,j});
		else
		{
			mp[p].push_back(j);
			mp[x][i]=-1;
//			i--;
		}
	}
	for(int i=0;i<mp[x].size();i++)
	{
		int j=mp[x][i];
		if(j==-1) continue;
		dfs(j,mp);
	}
}
void solve()
{
	vec.clear();
	cin>>n;
	map<int,vector<int>> mp;
	for(int i=2;i<=n;i++)
	{
		int x=ask(1,i);
		mp[x].push_back(i);
	}
    dfs(1,mp);
    cout<<"! ";
    for(auto [u,v]:vec)
    {
    	cout<<u<<" "<<v<<" ";
	}
	cout<<endl;
//	for(auto c:mp[1])
//	{
//		dfs(c,mp);
//	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}