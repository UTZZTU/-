#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+10;
int primes[N],cnt,n,flag;
bool st[N];
void init(int x)
{
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
signed main ()
{
	
	scanf("%lld",&n);
	init(n);
	printf("f(%lld)=",n);
	for(int i=0;i<cnt;i++)
	{
		int sum=0;
		for(int d=primes[i];d<=n;d*=primes[i])
		{
			int st=n+1-n/d*d,en=n+1-d;
			sum+=(en-st+d)/d*(en+st)/2;
		}
		if(sum==1)
		{
			if(flag)
			{
				printf("*");
			}
			printf("%lld",primes[i]);
			flag=1;
		}
		else
		{
			if(flag)
			{
				printf("*");
			}
			printf("%lld^%lld",primes[i],sum);
			flag=1;
		}
	}
	return 0;
}