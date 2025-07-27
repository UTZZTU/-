#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll n,q,a[100010][70],l,r,x;
int main ()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		for(int j=0;j<=61;j++)
		{
			a[i][j]=a[i-1][j]+((x>>j)&1);
		}
	}
	while(q--)
	{
		scanf("%lld%lld%lld",&l,&r,&x);
		ll res=0;
		for(ll i=0;i<=61;i++)
		{
			if(a[r][i]-a[l-1][i]) res+=1ll<<i;
		}
		cout<<(res|x)<<endl;
	}
	return 0;
}