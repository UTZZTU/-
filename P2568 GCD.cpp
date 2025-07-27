#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7+10;
ll primes[N],cnt,n,sum,phi[N],f[N];
bool st[N];
void init(int x)
{
	st[0]=st[1]=true;
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
	for(int i=0;i<cnt;i++)
	{
		ll tt=primes[i];
		sum+=2*f[n/tt]-1;
	}
	cout<<sum;
	return 0;
}