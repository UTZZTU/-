#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n;
string a,b,c;
void solve()
{
	map<string,set<string>> mp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(c=="accepted")
		{
			mp[b].insert(a);
		}
	}
	int maxx=0;
	string name;
	for(auto [u,v]:mp)
	{
//		cout<<u<<endl;
		if(v.size()>maxx)
		{
			name=u;
			maxx=v.size();
		}
	}
	cout<<name<<endl;
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