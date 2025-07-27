#include <bits/stdc++.h>
using namespace std;
int primes[3000],cnt,maxx,f[3000];
bool st[3000];
void init(int x)
{
	st[1]=true;
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
	init(2022);
	for(int i=0;i<cnt;i++)
	{
		for(int j=2022;j>=primes[i];j--)
		{
			f[j]=max(f[j],f[j-primes[i]]+primes[i]);
		}
	}
	cout<<f[2022];
	return 0;
}