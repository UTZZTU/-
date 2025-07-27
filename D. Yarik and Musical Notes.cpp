#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200010],sum;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		map<int,int> mp;
		sum=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			mp[a[i]]++;
		}	
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			int v=it->second;
			if(v>=2)
			{
				sum+=v*(v-1)/2;
			}
		}
		sum+=mp[1]*mp[2];
		printf("%lld\n",sum);
	}
	return 0;
}