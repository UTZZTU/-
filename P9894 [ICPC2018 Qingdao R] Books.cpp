#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,a[100010],res;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]==0) res++;
		}
		if(m==n) puts("Richman");
		else if(res>m) puts("Impossible");
		else
		{
			ll flag=0,minn=0x3f3f3f3f,sum=0;
			int cnt=m-res;
			if(cnt==0) flag=1;
			for(int i=1;i<=n;i++)
			{
				if(flag)
				{
					if(a[i])
					minn=min(minn,a[i]);
				}
				else
				{
					if(a[i])
					{
						sum+=a[i];
						cnt--;
						if(cnt==0) flag=1;
					}
				}
			}
//			cout<<sum<<" "<<minn<<endl;
			if(minn==0x3f3f3f3f) minn=0;
			printf("%lld\n",sum+max(0ll,minn-1));
		} 
	}
	return 0;
}