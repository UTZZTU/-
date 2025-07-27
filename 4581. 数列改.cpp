#include <bits/stdc++.h>
using namespace std;
const int mod = 9e6;
int a,b,ax,by,m,k;
string n;
int main ()
{
	cin>>a>>b>>ax>>by>>m>>k>>n;
	int x=0;
	for(int i=0;i<n.size();i++)
	{
		x=x*10+n[i]-'0';
		x%=mod;
	}
	for(int i=1;i<=x;i++)
	{
		int c=ax*b+by*a;
		c%=m;
		a=b;
		b=c;
	}
	for(int i=1;i<=k;i++)
	{
		int c=ax*b+by*a;
		c%=m;
		a=b;
		b=c;
		cout<<a<<endl;
	}
	return 0;
}