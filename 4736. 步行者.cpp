#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,m,n,p,res,f;
signed main  ()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		unordered_map<long long,long long> mp1,mp2;
		res=0;
		scanf("%lld%lld%lld",&m,&n,&p);
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				scanf("%lld",&f);
				mp1[k]=max(mp1[k],f);
				if(j==p)
				{
					mp2[k]=f;
				}
			}
		}
		for(int k=1;k<=n;k++) res+=mp1[k]-mp2[k];
		printf("Case #%d: %lld\n",i,res);
	}
	return 0;
}