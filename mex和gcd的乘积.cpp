#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[100010],l,r,mid,cnt,p[100010],pre[100010],post[100010],flag,maxx,pree[100010],postt[10010];
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		if(f[i]==0) flag=1;
	}
	if(!flag)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		p[f[i]]++;
		while(p[cnt])
		{
			cnt++;
		}
		pre[i]=cnt;
		if(i==1)
		{
			pree[i]=f[i];
		}
		else
		{
			if(f[i])
			pree[i]=__gcd(pree[i-1],f[i]);
			else pree[i]=pree[i-1];
		}
//		printf("%lld ",pree[i]);
	}
//	printf("\n");
	cnt=0;
	memset(p,0,sizeof(p));
	for(int i=n;i>=1;i--)
	{
		p[f[i]]++;
		while(p[cnt])
		{
			cnt++;
		}
		post[i]=cnt;
		if(i==n)
		{
			postt[i]=f[i];
		}
		else
		{
			if(f[i])
			postt[i]=__gcd(postt[i+1],f[i]);
			else postt[i]=postt[i+1];
		}
//		printf("%lld ",postt[i]);
	}
//	printf("\n");
	maxx=pree[n]*pre[n];
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
//			printf("%lld %lld\n",f[i-1],f[i+1]);
			if(i-1>=1)
			{
				if(f[i-1]==1)
				{
					maxx=max(maxx,(ll)2);
				}
				else
				maxx=max(maxx,f[i-1]);
			}
			if(i+1<=n)
			{
				if(f[i+1]==1)
				{
					maxx=max(maxx,(ll)2);	
				}
				else
				maxx=max(maxx,f[i+1]);
			}
//			maxx=max(pre[i]*pree[i],maxx);
//			maxx=max(maxx,post[i]*postt[i]);
		}
//		printf("%lld\n",maxx);
	}
	cout<<maxx;
	return 0;
}