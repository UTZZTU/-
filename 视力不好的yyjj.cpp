#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b[100010],a[100010],x,primes[100010],cnt;
bool st[100010];
//void init(ll x)
//{
//	st[1]=true;
//	for(int i=2;i<=x;i++)
//	{
//		if(!st[i]) primes[cnt++]=i;
//		for(int j=0;primes[j]*i<=x;j++)
//		{
//			st[primes[j]*i]=true;
//			if(i%primes[j]==0)
//			break;
//		}
//	}
//}
int main ()
{
//	init((ll)100010);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&b[i]);
	for(int i=n;i>=1;i--)
	{
		x=b[i];
		map<int,bool> mp;
		for(int j=2;j*i<=n;j++)
		{
			if(!mp[j*i])
			{
				x-=b[j*i];
				mp[j*i]=true;
			}
		}
		a[i]=x;
		b[i]=x;
	}
	cout<<a[1];
	return 0;
}