#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u[110],v[110],n;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld/%lld",&u[i],&v[i]);
	}
	if(n==1)
	{
		int flag1=1,flag2=1;
		int t=__gcd(u[1],v[1]);
		u[1]/=t,v[1]/=t;
		if(u[1]/v[1]!=0)
		{
			cout<<u[1]/v[1];
		}
		else flag1=0;
		u[1]%=v[1];
		if(u[1])
		{
			if(flag1) cout<<" ";
			cout<<u[1]<<"/"<<v[1];
		}
		else
		flag2=0;
		if(flag1+flag2==0) cout<<0;
	}
	else
	{
		ll p=v[1],q;
		for(int i=2;i<=n;i++)
		{
			q=v[i];
			int t=__gcd(p,q);
			p=p*q/t;
		}
		ll res=0;
		for(int i=1;i<=n;i++)
		{
			res+=p/v[i]*u[i];
		}
		int flag1=1,flag2=1;
		int t=__gcd(res,p);
		res/=t,p/=t;
		if(res/p!=0)
		{
			cout<<res/p;
		}
		else flag1=0;
		res%=p;
		if(res)
		{
			if(flag1) cout<<" ";
			cout<<res<<"/"<<p;
		}
		else flag2=0;
		if(flag1+flag2==0) cout<<0;
	}
	return 0;
}