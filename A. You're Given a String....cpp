#include <bits/stdc++.h>
using namespace std;
string s;
int maxx;
map<string,int> mp;
void solve()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		for(int j=i;j<s.size();j++)
		{
			string t=s.substr(i,j-i+1);
			mp[t]++;
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>=2)
		{
			maxx=max(maxx,(int)(it->first).size());
		}
	}
	cout<<maxx<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}