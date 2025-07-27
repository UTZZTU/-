#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,res,c[110];
map<string,int> mp;
string u,v[110];
signed main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u;
		mp[u]=i;
	}
	for(int i=0;i<=m;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		res+=c[mp[v[i]]];
	}
	cout<<res<<endl;
	return 0;
}