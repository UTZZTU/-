//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int x,y,g,res;
unordered_map<string,int> mp;
pair<string,string> p1[100010],p2[100010];
string a,b,c;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>x;
	for(int i=1;i<=x;i++)
	{
		cin>>a>>b;
		p1[i]={a,b};
	}
	cin>>y;
	for(int i=1;i<=y;i++)
	{
		cin>>a>>b;
		p2[i]={a,b};
	}
	cin>>g;
	while(g--)
	{
		cin>>a>>b>>c;
		mp[a]=g,mp[b]=g,mp[c]=g;
	}
	res=x;
	for(int i=1;i<=x;i++)
	{
		if(mp[p1[i].first]==mp[p1[i].second])
		res--;
	}
	for(int i=1;i<=y;i++)
	{
		if(mp[p2[i].first]==mp[p2[i].second])
		res++;
	}
	cout<<res;
	return 0;
}