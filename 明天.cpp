#include <bits/stdc++.h>
using namespace std;
string u,v="tomorrow";
int t;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>u;
		if(v.find(u)!=-1&&v.size()!=u.size()) puts("yes");
		else puts("no");
	}
	return 0;
}