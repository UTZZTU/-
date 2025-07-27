#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,res;
ll cut(ll x)
{
	ll sum=0;
	while(x!=1)
	{
		sum++;
		x=ceil(x*1.0/2);
	}
	return sum;
}
int main ()
{
	cin>>a>>b>>c;
	res+=cut(a);
	res+=cut(b);
	res+=cut(c);
	cout<<res;
	return 0;
}