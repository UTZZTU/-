#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int primes[N],cnt,p;
bool st[N];
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
	cin>>p;
	init(floor(sqrt(p)));
	for(int i=2;i<=floor(sqrt(p));i++)
	{
		if(p%i==0&&!st[i])
		{
			cout<<p/i;
			return 0;
		}
	}
	return 0;
}