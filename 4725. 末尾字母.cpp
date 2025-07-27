#include <bits/stdc++.h>
using namespace std;
string u;
char c;
int main ()
{
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		if(u[i]!=' '&&u[i]!='?')
		c=u[i];
	}
	if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u'||c=='Y'||c=='y')
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}