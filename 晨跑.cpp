#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,sum,ys;
ll fun(ll a,ll b)
{
	if(a<b)
	swap(a,b);
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main ()
{
	cin>>a>>b>>c;
	ys=fun(a,b);
	sum=a*b/ys;
	ys=fun(sum,c);
	sum=sum*c/ys;
	cout<<sum;
	return 0;
}