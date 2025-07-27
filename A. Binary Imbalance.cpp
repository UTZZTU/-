#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int i=0;
		for(i;i<n;i++)
		{
			if(s[i]!='1') break;
		}
		if(i==n) puts("NO");
		else puts("YES");
	}
	return 0;
}