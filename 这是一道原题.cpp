#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main ()
{
	cin>>a>>b>>c>>d;
	while(a>=3)
	{
		int x=a/3;
		b+=x;
		a%=3;
		a+=x;
	}
	while(b>=3)
	{
		int x=b/3;
		c+=x;
		b%=3;
		b+=x;
	}
	while(c>=3)
	{
		int x=c/3;
		d+=x;
		c%=3;
		c+=x;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
	return 0;
}