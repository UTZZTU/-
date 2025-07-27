#include <bits/stdc++.h>
using namespace std;
bool st[1010];
int primes[1010],cnt;
int n,k;
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
			{
				break;
			}
		}
	}
}
bool judge(int x)
{
	for(int i=1;i<cnt;i++)
	{
		if(primes[i]+primes[i-1]+1==x) return true;
	}
	return false;
}
void solve()
{
	init(1000);
	cin>>n>>k;
	int res=0;
	for(int i=2;i<=n;i++)
	{
		if(!st[i]&&judge(i))
		{
			res++;
		}
	}
	if(res>=k) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}