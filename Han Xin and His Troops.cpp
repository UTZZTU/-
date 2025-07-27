#include<bits/stdc++.h>
using namespace std;
#define ll __int128
ll n,m,a1,a2,m1,m2;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1;y=0;return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
	
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld",&a1,&m1);
	int flag=1;
	for(ll i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&a2,&m2);
		ll k1,k2,d,t;
		d=exgcd(a1,a2,k1,k2);
		if((m2-m1)%d)
		{
			flag=0;break;
		}
		k1*=(m2-m1)/d;
		t=a2/d;
		k1=(k1%t+t)%t;
		m1=a1*k1+m1;
		a1=a1/d*a2;
		if(a1<0)
			a1=-a1;
	}
	ll ans=(m1%a1+a1)%a1;
	if(!flag)puts("he was definitely lying");
    else if(ans>m)puts("he was probably lying");
    else print(ans);
}

