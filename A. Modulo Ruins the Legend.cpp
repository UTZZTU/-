#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f[100010],res;
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
signed main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		res+=f[i];
	}
	int a=n,b=n*(n+1)/2;
	int gcd1=__gcd(a,b);
	int gcd2=__gcd(gcd1,m);
	int h=res%gcd2,x,y,k1,k2;
	printf("%lld\n",h);
	h-=res;
	int d=exgcd(gcd1,m,k1,k2);
	k1*=(h/d)%m;
	k1%=m;
	d=exgcd(a,b,x,y);
	x*=k1;
	x=(x%m+m)%m;
	y*=k1;
	y=(y%m+m)%m;
	printf("%lld %lld\n",x,y);
	return 0;
}