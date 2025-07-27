#include <bits/stdc++.h>
using namespace std;
string u;
int main ()
{
	cin>>u;
	if(u[0]>='A'&&u[0]<='Z')
	cout<<u;
	else
	{
		u[0]-=32;
		cout<<u;
	}
	return 0;
}