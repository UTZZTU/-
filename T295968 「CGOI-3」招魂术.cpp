#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll t,n,a,b,x,y,f1[1000010],f2[1000010],res,tt,flag1,flag2,pos,q,h;
ll fast_power(ll a, ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&x,&y);
		res=1;
		f1[1]=x,f1[2]=y;
		f2[1]=a,f2[2]=b;
		flag1=flag2=0,pos=-1;
		res=(res*(x-a))%MOD;
		if(n>=2)
		res=(res*(y-b))%MOD;
		for(int i=3;i<=n;i++)
		{
			f1[i]=floor(sqrtl(f1[i-1]*f1[i-2]))+1;
			f2[i]=floor(sqrtl(f2[i-1]*f2[i-2]))+1;
			res=(res*(f1[i]-f2[i]))%MOD;
			if(f1[i]==f1[i-1])
			{
				flag1=1;
			}
			if(f2[i]==f2[i-1])
			{
				flag2=1;
			}
			if(flag1&&flag2)
			{
				pos=i;
				break;
			}
		}
		if(pos!=-1&&pos<n)
		{
			if(f1[pos]==f1[pos-1]&&f2[pos]==f2[pos-1])
			{
				tt=f1[pos]-f2[pos];
				res=(res*fast_power(tt,n-pos))%MOD;
			}
			else
			{
				if(f1[pos]==f1[pos-1])
				{
					q=f1[pos]+1-f2[pos];
					h=f1[pos]-f2[pos];
				}
				else
				{
					q=f1[pos]-1-f2[pos];
					h=f1[pos]-f2[pos];
				}
				if((n-pos)&1)
				{
					res=(res*q)%MOD;
				}
				res=(res*fast_power(q,(n-pos)/2))%MOD;
				res=(res*fast_power(h,(n-pos)/2))%MOD;
			}
		}
		printf("%lld\n",((res%MOD)+MOD)%MOD);
	}
	return 0;
}