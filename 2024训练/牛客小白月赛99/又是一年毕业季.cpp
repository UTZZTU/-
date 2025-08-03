#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll primes[5000010],cnt,n,a[200010];
bool st[5000010];
void init()
{
    st[1]=true;
	for(ll i=2;i<=5000000;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(ll j=0;primes[j]*i<=5000000;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0,j=1;i<cnt;i++)
	{
		while(j<=n&&a[j]<primes[i]) j++;
		if(j<=n&&primes[i]==a[j]) ;
		else
		{
			cout<<primes[i]<<endl;
			return;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}