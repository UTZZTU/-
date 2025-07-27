#include <bits/stdc++.h>
using namespace std;
bool check(int x)
{
	int res=0;
	string u;
	while(x)
	{
		u+='0'+x%2;
		x/=2;
	}
	for(int i=0;i<u.size()&&u[i]=='0';i++)
	res++;
	return res>=6;
}
int main ()
{
	for(int i=2023;;i++)
	{
		if(check(i))
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}