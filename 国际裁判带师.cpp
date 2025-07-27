#include <bits/stdc++.h>
using namespace std;
string s;
int a,b,res;
int get_zero(int x)
{
	int tt=0;
	if(x%10==0) tt++;
	x/=10;
	if(x%10==0) tt++;
	return tt;
}
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a') a++;
		else b++;
		res+=get_zero(a)+get_zero(b);
	}
	cout<<res;
	return 0;
}