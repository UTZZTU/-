#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll primes[10000010],cnt,n,tt[10000000],flag;
bool st[10000010];
void init(ll x)
{
	st[1]=true;
	for(ll i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(ll j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
void solve(ll a,ll b)
{
	ll res=0,cs=n-a+1,c=b;
	while(a%b==0)
	{
		a/=b;
		res++;
	}
	tt[c]+=res*cs;
}
int main ()
{
	init((ll)10000000);
	scanf("%lld",&n);
	for(ll i=2;i<=n;i++)
	{
		if(!st[i]) 
		{
			solve(i,i);
			for(ll j=i+i;j<=n;j+=i)
			{
				solve(j,i);
			}
		}
	}
	printf("f(%d)=",n);
	for(int i=0;i<cnt;i++)
	{
//		printf("%d %d\n",primes[i],tt[primes[i]]);
		if(tt[primes[i]])
		{
			if(flag) printf("*");
			if(tt[primes[i]]==1) printf("%d",primes[i]);
			else printf("%d^%d",primes[i],tt[primes[i]]);
			flag=1;
		}
	}
	return 0;
}