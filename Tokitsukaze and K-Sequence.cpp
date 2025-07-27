#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010],k,f[100010],res,ans;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp;
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			a[k]++;
		}
		for(int i=1;i<=100000;i++)
		{
			if(a[i])
			{
				mp[a[i]]++;
			}
		}
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(it->first==1)
			{
				f[1]+=it->second;
				f[2]-=it->second;
			}
			else
			{
				f[2]+=it->second;
				f[it->first+1]-=it->second;
				f[it->first]+=it->second;
				f[it->first+1]-=it->second;
			}
		}
		res=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=f[i];
			res+=ans;
			printf("%d\n",res);
		}
	}
	return 0;
}