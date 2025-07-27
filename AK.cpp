#include <bits/stdc++.h>
using namespace std;
int n;
string u,v;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u;
		v=u.substr(u.size()-2,u.size());
		if(v=="AK")
		{
			v=u.substr(0,u.size()-2);
			cout<<v;
			return 0;
		}
	}
	return 0;
}