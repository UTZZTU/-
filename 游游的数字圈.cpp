#include <bits/stdc++.h>
using namespace std;
string u;
int res;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='0'||u[i]=='6'||u[i]=='9')
		res++;
		else if(u[i]=='8') res+=2;
	}
	cout<<res;
	return 0;
}