#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
int k,res=1,primes[5000010],cnt;
bool st[5000010];
void init(int x)
{
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
void solve()
{
	init(5000000);
	cin>>k;
	for(int i=0;i<cnt;i++)
	{
		int x=primes[i];
		int pp=x;
		if(x>k) break;
		while(pp<=k)
		{
			res=res*x%mod;
			pp*=x;
		}
	}
	cout<<res<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}