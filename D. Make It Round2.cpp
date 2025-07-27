#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,x,y,cnt2,cnt5;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		cnt2=cnt5=0;
		x=n,y=m;
		while(x%10==0)
		{
			x/=10;
		}
		while(x%2==0)
		{
			x/=2;
			cnt2++;
		}
		while(x%5==0)
		{
			x/=5;
			cnt5++;
		}
		if(cnt2)
		{
			int res=1;
			while(res*5<=m&&cnt2)
			{
				res*=5;
				n*=5;
				cnt2--;
			}
			while(res*10<=m)
			{
				res*=10;
				n*=10;
			}
			int pp=m/res;
			n*=pp;
		}
		else if(cnt5)
		{
			int res=1;
			while(res*2<=m&&cnt5)
			{
				res*=2;
				n*=2;
				cnt5--;
			}
			while(res*10<=m)
			{
				res*=10;
				n*=10;
			}
			int pp=m/res;
			n*=pp;
		}
		else
		{
			int res=1;
			while(res*10<=m)
			{
				res*=10;
				n*=10;
			}
			int pp=m/res;
			n*=pp;
		}
		printf("%lld\n",n);
	}
	return 0;
}