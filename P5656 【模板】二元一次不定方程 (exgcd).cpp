#include <bits/stdc++.h>
using namespace std;
#define int long long
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int t,a,b,c;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		int x,y;
		int gcds=exgcd(a,b,x,y);
		if(c%gcds)
		{
			puts("-1");
		}
		else
		{
			x*=c/gcds;
			y*=c/gcds;
			a/=gcds;
			b/=gcds;
			int r=floor(1.0L*(y-1)/a);
			int l=ceil(1.0L*(1-x)/b);
			if(r>=l)
			{
				printf("%lld %lld %lld %lld %lld\n",r-l+1,x+l*b,y-r*a,x+r*b,y-l*a);
			}
			else
			{
				printf("%lld %lld\n",x+l*b,y-r*a);
			}
		}
	}
	return 0;
}