#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,l,r,mid,k,cs;
bool check(ll x)
{
	if(x<=k)
	cs=x;
	else
	{
		cs=0;
		ll a=x,b=x;
		cs+=a/k*b;
		a%=k;
		if(a!=0)
		{
			cs+=b/k*a;
			b%=k;
			if(b!=0)
			{
				cs+=min(a,b);
			}
		}
	}
	if(n>=cs)
	return true;
	else
	return false;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
//		if(n==2)
//		printf("-1\n");
        l=0,r=n;
        if(n&1)
        k=n/2+1;
        else
        k=n/2;
	    while(l<r)
	    {
	    	mid=(l+r+1)>>1;
	    	if(check(mid))
	    	l=mid;
	    	else
	    	r=mid-1;
		}
		if(n/l<=l)
		printf("%lld\n",l);
		else
		printf("-1\n");
	}
	return 0;
}