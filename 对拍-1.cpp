#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,k,num[100010],h[100010],f[100010],x,tt;
ll dfs(ll level,ll cnt)
{
	ll res=0;
	for(int i=level;i>=max((ll)1,level-cnt+1);i--)
	{
		if(i==level) res+=num[i];
		else
		{
			if(h[i]==h[i+1]) res+=num[i];
			else
			{
				res+=dfs(i,k);
				break;
			}
		}
	}
	f[level]=res;
	return res;
}
int main ()
{
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
	}
	tt=dfs(n,k);
	while(q--)
	{
		scanf("%lld",&x);
		printf("%lld\n",f[x]);
	}
	return 0;
}