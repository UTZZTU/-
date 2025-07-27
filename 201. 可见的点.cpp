#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int phi[N],primes[N],cnt,c,n,f[N];
bool st[N];
void init(int n)
{
	st[1]=true;
	phi[1]=1;
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
	init(1000);
	f[1]=phi[1];
	for(int i=2;i<=1000;i++)
	f[i]=f[i-1]+phi[i];
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,2*f[n]+1);
	}
	return 0;
}