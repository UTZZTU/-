#include <bits/stdc++.h>
using namespace std;
int n,primes[3010],cnt,res;
bool st[3010];
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
bool judge(int x)
{
	int sum=0;
	for(int i=0;i<cnt;i++)
	{
		if(primes[i]>x) break;
		if(x%primes[i]==0) sum++;
	}
	return sum==2;
}
void solve()
{
	init(3000);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(judge(i)) res++;
	}
	cout<<res<<endl;
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