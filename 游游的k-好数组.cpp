#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,k,n,x,a[100010],tt[100010],maxx;
bool check(ll x)
{
	ll res=0;
	for(int i=k;i<=n;i++)
	{
		if(tt[i]-tt[i-k]>x) return false;
		
	}
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		maxx=0;
		scanf("%d%d%d",&n,&k,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			tt[i]=tt[i-1]+a[i];
			if(i>=k)
			{
				maxx=max(maxx,tt[i]-tt[i-k]);
			}
		}
		ll l=maxx,r=maxx+x;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		if(check(l))
		{
			
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}