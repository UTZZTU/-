#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,c,f[200010],sum[200010],pos,ans;
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&c);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&f[i]);
			sum[i]=sum[i-1]+f[i];
		}
		ans=sum[1],pos=1;
		for(int i=2;i<=n;i++)
		{
			if(ans+f[i]>=i*c)
			{
				ans=sum[i];
				pos=i;
			}
		}
		if(pos==n)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}