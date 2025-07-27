#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,y,z,a,b;
ll res,maxx;
map<int,ll> mp;
int main ()
{
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[0]+=x;
		mp[a]-=x;
		mp[a]+=y;
		mp[b+1]-=y;
		mp[b+1]+=z;
		mp[2000000001]-=z;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		res+=it->second;
		maxx=max(maxx,res);
	}
	printf("%lld",maxx);
	return 0;
}