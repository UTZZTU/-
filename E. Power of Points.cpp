#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x[200010],cz[200010],pre[200010],prr[200010],poo[200010],post[200010],c[200010];
ll get_pre(ll x)
{
	if(x==0) return 0;
	ll len=x-1+1;
	return len*(len+1)/2;
}
ll get_post(ll x)
{
	if(x>n) return 0;
	ll len=n-x+1;
	return len*(len+1)/2;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		map<ll,ll> mp;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			c[i]=x[i];
		}
		sort(x+1,x+1+n);
//		cz[1]=x[1];
		for(int i=2;i<=n;i++)
		{
			cz[i]=x[i]-x[i-1];
		}
		for(ll i=1;i<n;i++)
		{
			prr[i]=prr[i-1]+i*cz[i+1];
//			printf("%lld ",prr[i]);
		}
//		printf("\n");
		poo[n+1]=0;
		for(ll i=n;i>=1;i--)
		{
			ll j=n-i;
			poo[i]=poo[i+1]+j*cz[i+1];
//			printf("%lld ",poo[i]);
		}
//		printf("\n");
		for(int i=1;i<=n;i++)
		{
			mp[x[i]]=prr[i-1]+poo[i]+n;
//			cout<<x[i]<<endl;
//			printf("%lld ",);
		}
		for(int i=1;i<=n;i++)
		{
//			printf("%lld ",mp[cz[i]]);
			cout<<mp[c[i]]<<" ";
		}
		printf("\n");//1+get_pre(i-1)+
	}
	return 0;
}