#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,q,k,x,u,v;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		map<int,int> mp;
		scanf("%lld%lld",&n,&q);
		u=n;
		for(int i=2;i*i<=u;i++)
		{
			if(u%i==0)
			{
				while(u%i==0)
				{
					mp[i]++;
					u/=i;
				}
			}
		}
		if(u>1) mp[u]++;
		while(q--)
		{
			scanf("%lld",&k);
			if(k==1)
			{
				scanf("%lld",&x);
				for(int i=2;i*i<=x;i++)
				{
					if(x%i==0)
					{
						while(x%i==0)
						{
							mp[i]++;
							x/=i;
						}
					}
				}
				if(x>1) mp[x]++;
				map<int,int> pm;
				for(auto it=mp.begin();it!=mp.end();it++)
				{
					u=it->second+1;
					for(int i=2;i*i<=u;i++)
					{
						if(u%i==0)
						{
							while(u%i==0)
							{
								pm[i]++;
								u/=i;
							}
						}
					}
					if(u>1) pm[u]++;
				}
				int flag=1;
				for(auto it=pm.begin();it!=pm.end();it++)
				{
					u=it->first,v=it->second;
					if(mp[u]<v)
					{
						flag=0;
						break;
					}
				}
				if(flag) puts("YES");
				else puts("NO");
			}
			else
			{
				u=n;
				mp.clear();
				for(int i=2;i*i<=u;i++)
				{
					if(u%i==0)
					{
						while(u%i==0)
						{
							mp[i]++;
							u/=i;
						}
					}
				}
				if(u>1) mp[u]++;
			}
		}
	}
	return 0;
}