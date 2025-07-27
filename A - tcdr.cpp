#include <bits/stdc++.h>
using namespace std;
string u,v;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]!='a'&&u[i]!='e'&&u[i]!='i'&&u[i]!='o'&&u[i]!='u')
		v+=u[i];
	}
	cout<<v;
	return 0;
}