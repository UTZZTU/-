#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll x,maxx;
void dfs(ll x,ll res)
{
	if(x==0)
	{
		maxx=max(maxx,res);
		return;
	}
	for(ll i=1;i<=x;i++)
	{
		dfs(x%i,res+1);
	}
}
void solve()
{
	maxx=0;
	cin>>x;
	dfs(x,0ll);
	cout<<maxx<<endl;
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