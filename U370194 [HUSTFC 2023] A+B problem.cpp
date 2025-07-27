#include <bits/stdc++.h>
using namespace std;
char a,b;
string s;
int res;
int main ()
{
	cin>>a>>b;
	res=(a-'A')+(b-'A');
	if(res==0)
	{
		puts("A");
		return 0;
	}
	while(res)
	{
		s+=(res%26+'A');
		res/=26;
	}
	reverse(s.begin(),s.end());
	cout<<s;
	return 0;
}