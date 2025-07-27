#include <bits/stdc++.h>
using namespace std;
bool st[1000010];
int primes[1000010],cnt;
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
	int n;
	cin>>n;
	init(n);
	for(int i=0;i<cnt;i++)
	{
		int p=primes[i];
		int s=0;
		for(int j=n;j;j/=p) s+=j/p;
		printf("%d %d\n",p,s);
	}
	return 0;
}