#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r;
ll primes[50010],f[1000010],cnt,ans;
bool st[50010];
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
	init(50000);
	cin>>l>>r;
	for(int i=0;i<cnt;i++)
	{
		ll u=primes[i];
		for(ll j=max(2*u,(l+u-1)/u*u);j<=r;j+=u)
		f[j-l]=1;
	}
	for(int i=0;i<=r-l;i++)
	{
		if(!f[i]&&i+l!=1)
		ans++;
	}
	cout<<ans;
	return 0;
}