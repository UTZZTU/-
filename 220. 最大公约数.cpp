#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000010;
ll phi[N],primes[N],cnt,n,f[N],res;
bool st[N];
void init(int n)
{
	st[1]=true;
	phi[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			phi[i]=i-1;
			primes[cnt++]=i;
		}
		for(int j=0;primes[j]*i<=n;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0)
			{
				phi[i*primes[j]]=phi[i]*primes[j];
				break;
			}
			phi[i*primes[j]]=phi[i]*(primes[j]-1);
		}
	}
}
int main ()
{
	scanf("%lld",&n);
	init(n);
	f[1]=phi[1];
	for(int i=2;i<=n;i++)
	f[i]=f[i-1]+phi[i];
	for(int i=0;i<cnt;i++)
	{
		int p=primes[i];
		res+=2*f[n/p]+1;
	}
	printf("%lld",res);
	return 0;
}