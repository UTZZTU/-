#include <bits/stdc++.h>
using namespace std;
int t,n,a[10010],primes[1000010],cnt,k,flag;
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
			if(i%primes[j]==0) break;
		}
	}
}
int main ()
{
	init(1e6);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=1;
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(int j=0;j<cnt&&primes[j]*primes[j]<=k;j++)
			{
				if(k%primes[j]==0)
				{
					while(k%primes[j]==0)
					{
						mp[primes[j]]++;
						k/=primes[j];
					}
				}
			}
			if(k>1) mp[k]++;
		}
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(it->second%n!=0)
			{
				flag=0;
				break;
			}
		}
		if(!flag) puts("NO");
		else puts("YES");
	}
	return 0;
}