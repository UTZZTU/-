#include <bits/stdc++.h>
using namespace std;
string u,v;
int t;
bool check(string u,string v)
{
	map<char,int> mp;
	for(int i=0;i<u.size();i++)
	{
		mp[u[i]]++;
	}
	for(int i=0;i<v.size();i++)
	{
		mp[v[i]]--;
		if(mp[v[i]]<0)
		return false;
	}
	return true;
}
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u>>v;
		if(check(u,v))
		cout<<"Y"<<endl;
		else
		cout<<"N"<<endl;
	}
	return 0;
}