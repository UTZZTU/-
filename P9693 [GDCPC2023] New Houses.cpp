#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,res;
struct node
{
	int a,b;
	int cz;
}s[500010];
bool cmp(node x,node y)
{
	return x.cz>y.cz;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		res=0;
		scanf("%lld%lld",&n,&m);
		s[0].a=0,s[0].b=0,s[0].cz=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&s[i].a,&s[i].b);
			s[i].cz=s[i].b-s[i].a;
		}
		sort(s+1,s+1+n,cmp);
		if(n==1)
		{
			printf("%lld\n",s[1].b);
			continue;
		}
		int i=1;
		for(i;i<=n;i++)
		{
			if(s[i].cz>0)
			{
				if(m-2>=n-i)
				{
					m-=2;
					res+=s[i].b;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		if(i==n)
		{
			res=max(res+s[i].b,res-s[i-1].b+s[i-1].a+s[i].a);
		}
		else
		{
			for(i;i<=n;i++)
			{
				res+=s[i].a;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
1+2*x+y=m
*/