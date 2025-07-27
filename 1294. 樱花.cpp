#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll res=1;
int primes[1000100],cnt,n;
bool st[1000010];
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
	cin>>n;
	init(n);
	for(int i=0;i<cnt;i++)
	{
		ll s=0;
		for(int j=n;j;j/=primes[i])
		s+=j/primes[i];
		res=res*(2*s+1)%MOD;
	}
	cout<<res;
	return 0;
}