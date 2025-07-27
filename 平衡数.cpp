#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>s;
		if(s[0]-'0'+s[1]-'0'==s[2]-'0'+s[3]-'0')
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}