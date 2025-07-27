#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
int flag,n;
int main ()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==',')
		{
			if(flag==1)
			{
				t+=".";
			}
			else
			t+=",";
		}
		else if(s[i]=='(')
		{
			flag=1;
			t+=s[i];
		}
		else if(s[i]==')')
		{
			flag=0;
			t+=s[i];
		}
		else t+=s[i];
	}
	cout<<t;
	return 0;
}