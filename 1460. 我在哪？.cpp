#include <bits/stdc++.h>
using namespace std;
int n,l,r,mid;
string u;
bool check(int x)
{
	map<string,int> mp;
	string v;
	for(int i=0;i<x;i++)
	{
		v+=u[i];
	}
	mp[v]++;
	for(int i=x;i<n;i++)
	{
		v+=u[i];
		v.erase(0,1);
		mp[v]++;
		if(mp[v]>1)
		return false;
	}
	return true;
}
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	l=1,r=n;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
}