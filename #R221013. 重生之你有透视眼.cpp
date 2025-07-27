#include <bits/stdc++.h>
using namespace std;
string u;
int main ()
{
	cin>>u;
	if(!(u.size()&1))
	{
		cout<<"No";
		return 0;
	}
	for(int i=0;i<u.size()/2;i++)
	{
		if(u[i]!=u[u.size()-1-i])
		{
			cout<<"No";
			return 0;
		}
	}
	for(int i=0;i<u.size()/4;i++)
	{
		if(u[i]!=u[u.size()/2-1-i])
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}