#include <bits/stdc++.h>
using namespace std;
string s;
int res,l;
int main ()
{
	cin>>s;
	l=s.size();
	for(int i=0;i<l-1;i++)
	{
		if(((s[i]-'0')+(s[l-1]-'0'))%2==0)
		{
			res++;
		}
	}
	cout<<res;
	return 0;
}