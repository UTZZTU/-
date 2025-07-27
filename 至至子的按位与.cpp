#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,t;
int maxx;
string u,v;
int main ()
{
	cin>>a>>b;
	while(a)
	{
		u+='0'+a%2;
		a/=2;
	}
	while(b)
	{
		v+='0'+b%2;
		b/=2;
	}
    while(u.size()<63)
    u+='0';
	while(v.size()<63)
	v+='0';
	for(int i=62;i>=0;i--)
	{
		t=(ll)pow(2,i);
		if(u[i]==v[i])
		{
			c+=t;
		}
	}
	cout<<c;
	return 0;
}