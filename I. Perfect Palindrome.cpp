#include <bits/stdc++.h>
using namespace std;
int t,n,maxx;
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		map<char,int> mp;
		cin>>s;
		n=s.size();
		for(int i=0;i<n;i++)
		{
			mp[s[i]]++;
		}
		maxx=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			maxx=max(maxx,it->second);
		}
		cout<<n-maxx<<endl;
	}
	return 0;
}