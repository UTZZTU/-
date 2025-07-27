#include <bits/stdc++.h>
using namespace std;
int n;
string u;
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	for(int i=0;i<u.size();i+=2)
	{
		if(u[i]=='7'&&u[i+1]=='z')
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}