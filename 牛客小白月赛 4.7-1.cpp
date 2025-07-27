#include <bits/stdc++.h>
using namespace std;
string u;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]>='a'&&u[i]<='z')
		u[i]-=32;
		else if(u[i]>='A'&&u[i]<='Z')
		u[i]+=32;
	}
	cout<<u;
	return 0;
}