#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,l,r,x,a,b,res;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld%lld%lld",&l,&r,&x);
		scanf("%lld%lld",&a,&b);
		if(a==b)
		cout<<0<<endl;
		else if(a>b)
		{
			if(abs(a-b)>=x)
			cout<<1<<endl;
			else if(b-x>=l||a+x<=r)
			cout<<2<<endl;
			else if(a-x>=l&&r-b>=x)
			cout<<3<<endl;
			else
			cout<<-1<<endl;
		}
		else if(a<b)
		{
			if(abs(a-b)>=x)
			cout<<1<<endl;
			else if(b+x<=r||a-x>=l)
			cout<<2<<endl;
			else if(a+x<=r&&b-l>=x)
			cout<<3<<endl;
			else
			cout<<-1<<endl;
		}
	}
	return 0;
}