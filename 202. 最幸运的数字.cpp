#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	return b? gcd(b,a%b):a;
}
ll qmul(ll a,ll b,ll p)
{
	ll res=0;
	while(b)
	{
		if(b&1)
		res=(res+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return res;
}
ll qmi(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=qmul(res,a,p)%p;
		a=qmul(a,a,p)%p;
		b>>=1;
	}
	return res;
}
ll get_euler(ll c)
{
	ll res=c;
	for(ll i=2;i<=c/i;i++)
	{
		if(c%i==0)
		{
			while(c%i==0) c/=i;
			res=res/i*(i-1);
		}
	}
	if(c>1)
	res=res/c*(c-1);
	return res;
}
int main ()
{
	int t=1;
	ll l;
	while(cin>>l,l)
	{
		ll d=gcd(l,(ll)8);
		ll C=l*9/d;
		ll phi=get_euler(C);
		ll res=1e18;
		if(C%2==0||C%5==0) res=0;
		else
	    {
	    	for(ll d=1;d*d<=phi;d++)
	    	{
	    		if(phi%d==0)
	    		{
	    			if(qmi(10,d,C)==1) res=min(res,d);
	    			if(qmi(10,phi/d,C)==1) res=min(res,phi/d);
				}
			}
		}
		printf("Case %d: %lld\n",t++,res);
	}
	return 0;
}