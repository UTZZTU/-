#include <bits/stdc++.h>
using namespace std;
int primes[20010],cnt,n;
bool st[20010];
void init(int x)
{
	st[0]=st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0)
			break;
		}
	}
}
int main ()
{
	init(20000);
	cin>>n;
	for(int i=0;primes[i]<n&&i<cnt;i++)
	{
		for(int j=0;primes[j]<n&&j<cnt;j++)
		{
			if(!st[n-primes[i]-primes[j]])
			{
				cout<<primes[i]<<" "<<primes[j]<<" "<<(n-primes[i]-primes[j]);
				return 0;
			}
		}
	}
	return 0;
}