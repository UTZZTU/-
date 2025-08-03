#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
bool st[10000010];
int primes[10000010],cnt,a,b,pp[10000010];
void init()
{
	st[1]=true;
	for(int i=2;i<=10000000;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=10000000;j++)
		{
			st[primes[j]*i]=true;
			pp[primes[j]*i]=1;
			if(i%primes[j]==0) break;
		}
	}
	for(int i=1;i<=10000000;i++)
	{
		pp[i]+=pp[i-1];
	}
}
void solve()
{
	init();
	while(cin>>a>>b)
	{
		cout<<pp[b]-pp[a-1]<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}