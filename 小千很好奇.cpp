#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int primes[N],cnt,t,l,r;
bool st[N];
void init(int x)
{
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[++cnt]=i;
		for(int j=1;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
int main ()
{
	init(1e6);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",upper_bound(primes+1,primes+1+cnt,r)-lower_bound(primes+1,primes+1+cnt,l));
	}
	return 0;
}