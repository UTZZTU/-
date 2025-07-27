#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,d[100010],b[100010],res,t1,ans;
int main ()
{
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&d[i],&b[i]);
	}
	d[n+1]=t+1;
	for(int i=1;i<=n+1;i++)
	{
		if(ans>=d[i]-t1)
		{
			ans-=d[i]-t1;
			res+=d[i]-t1;
			t1=d[i];
			ans+=b[i];
		}
		else
		{
			res+=ans;
			ans=0;
			t1=d[i];
			ans+=b[i];
		}
	}
	cout<<res;
	return 0;
}