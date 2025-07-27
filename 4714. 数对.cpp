#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,ll> mp;
string u;
ll ans;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	mp[u[i]]++;
	for(auto it=mp.begin();it!=mp.end();it++)
	ans+=it->second*(it->second-1);
	ans+=u.size();
	cout<<ans;
	return 0;
}