#include <bits/stdc++.h>
using namespace std;
string s;
int main ()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			s[i]='A'+(s[i]-'A'+1)%26;
		}
		else if(s[i]>='a'&&s[i]<='z')
		{
			s[i]='a'+((s[i]-'a'-1)%26+26)%26;
		}
	}
	cout<<s;
	return 0;
}