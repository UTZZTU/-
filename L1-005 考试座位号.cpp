#include <bits/stdc++.h>
using namespace std;
map<int,pair<string,int>> mp;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		pair<string,int> p;
		int v;
		cin>>p.first>>v>>p.second;
		mp[v]=p;
	}
	int m;
	cin>>m;
	for(int i=1,k;i<=m;i++)
	{
		cin>>k;
		cout<<mp[k].first<<" "<<mp[k].second<<endl;
	}
	return 0;
}