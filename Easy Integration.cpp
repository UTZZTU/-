#include <bits/stdc++.h>
using namespace std;
string s,t;
int main ()
{
	while(cin>>s>>t)
	{
		if(s+t>t+s) printf(">\n");
		else if(s+t<t+s) printf("<\n");
		else printf("=\n");
	}
	return 0;
}