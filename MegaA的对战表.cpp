#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
vector<string> vec;
int maxx,n;
string u,v;
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		mp[u]++;
		mp[v]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		maxx=max(maxx,it->second);
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second==maxx)
		{
			vec.push_back(it->first);
		}
	}
	sort(vec.begin(),vec.end());
	cout<<vec.size()<<" "<<maxx<<endl;
	for(int i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
	return 0;
}