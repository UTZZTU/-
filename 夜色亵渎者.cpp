#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300010],b[300010],res;
map<int,int> mp;
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		b[i]^=a[i];
		mp[b[i]]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		int u=it->second;
		res+=u*(u-1);
	}
	printf("%lld",res+n);
	return 0;
}
/*
ai bj
aj bi
*/