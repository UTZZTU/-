#include <bits/stdc++.h>
using namespace std;
string u,v;
int ans;
int main ()
{
	cin>>u>>v;
	for(int i=0;i<u.size()-1;i++)
	{
		if(u[i]!=v[i])
		{
			ans++;
			if(u[i+1]=='*')
			u[i+1]='o';
			else
			u[i+1]='*';
		}
	}
	cout<<ans;
	return 0;
}