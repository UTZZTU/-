#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll primes[50000],cnt,phi[50000],f[50000],n;
bool st[50000];
void init(ll x)
{
	st[1]=true;
	phi[1]=1;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i,phi[i]=i-1;
		for(int j=0;primes[j]*i<=x;j++)
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
	for(int i=1;i<=x;i++)
	f[i]=f[i-1]+phi[i];
}
int main ()
{
	cin>>n;
	init(n);
	if(n==1)
	cout<<0;
	else
	cout<<2*f[n-1]+1;
	return 0;
}