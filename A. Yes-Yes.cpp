#include <bits/stdc++.h>
using namespace std;
int t,e,flag;
string s,u="Yes";
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		flag=1;
		if(s[0]=='e') e=1;
		else if(s[0]=='s') e=2;
		else if(s[0]=='Y') e=0;
		else
		{
			puts("NO");
			continue;
		}
		for(int i=1;i<s.size();i++)
		{
			e++;
			e%=3;
			if(s[i]!=u[e])
			{
				flag=0;
				break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}