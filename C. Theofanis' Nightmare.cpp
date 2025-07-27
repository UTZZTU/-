#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100010],sum,res,cnt;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		res=0;
		cnt=1;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			res+=a[i];
		}
		res-=a[1];
		sum+=a[1];
		for(int i=2;i<=n;i++)
		{
			if(res>0)
			{
				cnt++;
			}
			sum+=a[i]*cnt;
			res-=a[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}