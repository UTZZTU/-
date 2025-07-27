#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		getchar();
		cin>>s;
		string u;
		for(int i=0;i<s.size();i++)
		{
			if(u.empty())
			{
				u+=s[i];
				printf("%c",s[i]);
			}
			else
			{
				if(s[i]==u[0])
				{
					u.clear();
				}
				else
				{
					u+=s[i];
				}
			}
		}
		printf("\n");
	}
	return 0;
}