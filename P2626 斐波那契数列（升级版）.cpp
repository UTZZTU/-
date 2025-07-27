#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)pow(2,31);
ll n,f[50],tt,primes[10000010],cnt;
int main ()
{
	cin>>n;
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++)
	f[i]=(f[i-1]+f[i-2])%MOD;
	tt=f[n];
	for(int i=2;i*i<=f[n];i++)
	{
		if(tt%i==0)
		while(tt%i==0) primes[cnt++]=i,tt/=i;
	}
	if(tt>1)
	primes[cnt++]=tt;
	printf("%lld=",f[n]);
	for(int i=0;i<cnt;i++)
	{
		if(i!=0)
		printf("*");
		printf("%lld",primes[i]);
	}
	return 0;
}