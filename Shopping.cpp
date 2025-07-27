#include <bits/stdc++.h>
using namespace std;
int k,n,m,ans;
map<string,int> mp;
string u,v="memory";
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		mp[u]=0;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		ans=0;
		for(int j=1;j<=n;j++)
		{
			cin>>k>>u;
			mp[u]+=k;
		}
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(it->second>mp[v])
			ans++;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}