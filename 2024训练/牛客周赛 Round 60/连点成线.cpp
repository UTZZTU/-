#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
map<int,set<int>> mp1,mp2;
int n,m,maxx;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp1[x].insert(y);
		mp2[y].insert(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(mp1[i].size())
		maxx=max(maxx,*mp1[i].rbegin()-*mp1[i].begin());
		if(mp2[i].size())
		maxx=max(maxx,*mp2[i].rbegin()-*mp2[i].begin());
	}
	cout<<maxx;
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