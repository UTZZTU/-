#include <bits/stdc++.h>
using namespace std;
int f[100010],dp[100010],t,n,cnt,k,res,cz,ans,sz,l;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
	    map<int,int> mp;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			mp[k]++;
		}
		cout<<n-mp[0]<<endl;
	}
	return 0;
}