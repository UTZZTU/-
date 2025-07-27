#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll t,n,primes[10000100],cnt,p,q;
bool st[10000100];
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
	init(10000000);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<cnt;i++)
		{
			if(n%primes[i]==0)
			{
				if(n%(primes[i]*primes[i])==0)
				{
					p=primes[i];
					q=n/(primes[i]*primes[i]);
				}
				else
				{
					q=primes[i];
					p=(ll)sqrt(n/q);
				}
				break;
			}
		}
		printf("%lld %lld\n",p,q);
	}
	return 0;
}