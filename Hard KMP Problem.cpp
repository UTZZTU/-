#include <bits/stdc++.h>
using namespace std;
int t;
string u,v;
int main ()
{
	cin>>t;
	while(t--)
	{
		map<char,int> mp1,mp2;
		int minn=0x3f3f3f3f;
		cin>>u>>v;
		for(int i=0;i<u.size();i++)
		{
			mp1[u[i]]++;
		}
		for(int i=0;i<v.size();i++)
		{
			mp2[v[i]]++;
		}
		for(auto it=mp2.begin();it!=mp2.end();it++)
		{
			char c=it->first;
			int pos=it->second;
			minn=min(minn,mp1[c]/pos);
		}
		cout<<minn<<endl;
	}
	return 0;
}