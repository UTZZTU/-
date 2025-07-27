#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi[10000010],primes[10000010],cnt,pos;
bool st[10000010];
void init(int n)
{
	st[1]=true;
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			primes[cnt++]=i;
			phi[i]=i-1;
		}
		for(int j=0;primes[j]*i<=n;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0)
			{
				phi[primes[j]*i]=primes[j]*phi[i];
				break;
			}
			phi[primes[j]*i]=(primes[j]-1)*phi[i];
		}
	}
}
int main ()
{
	init(100);
	for(int i=1;i<=100;i++)
	{
		cout<<phi[i]<<endl;
	}
	return 0;
}