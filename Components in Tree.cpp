#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,u,v,f[100010],res;
ll C(ll x,ll y)
{
	return x*(x-1)/2;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		f[u]++,f[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]>=2)
		res+=C(f[i],2);
	}
	cout<<res;
	return 0;
}