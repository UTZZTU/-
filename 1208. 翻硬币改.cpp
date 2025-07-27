#include <bits/stdc++.h>
using namespace std;
string u,v;
int res=0;
int main ()
{
	cin>>u>>v;
	for(int i=0;i<u.size()-1;i++)
	{
		if(u[i]==v[i])
		;
		else
		{
			res++;
			if(u[i+1]=='*')
			u[i+1]='o';
			else
			u[i+1]='*';
		}
	}
	cout<<res;
	return 0;
}