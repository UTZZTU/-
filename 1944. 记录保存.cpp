#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
string u,u1,u2,u3;
int maxn,n;
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u1>>u2>>u3;
		u=u1+" "+u2+" "+u3;
		mp[u]++;
		u=u1+" "+u3+" "+u2;
		mp[u]++;
		u=u2+" "+u1+" "+u3;
		mp[u]++;
		u=u2+" "+u3+" "+u1;
		mp[u]++;
		u=u3+" "+u1+" "+u2;
		mp[u]++;
		u=u3+" "+u2+" "+u1;
		mp[u]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		maxn=max(maxn,it->second);
	}
	cout<<maxn;
	return 0;
}