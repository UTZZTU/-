#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010],pre[200010],res,minn=0x3f3f3f3f3f3f3f3f,post[200010],pp[200010];
signed main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&a[i]);
		if(i>=2) pre[i]=a[i]-a[i-1];
	}
	if((2*n-k)&1)
	{
		if(k==1)
		{
			cout<<0;
			return 0;
		}
		post[k+1]=0;
		for(int i=2;i<=k;i+=2)
		{
			pp[i]=a[i]-a[i-1]+pp[i-2];
		}
		for(int i=k-1;i>=1;i-=2)
		{
			post[i]=post[i+2]+a[i+1]-a[i];
		}
		for(int i=1;i<=k;i++)
		{
			if(i==1)
			{
				minn=min(minn,post[2]);
			}
			else if(i==k)
			{
				minn=min(minn,pp[k-1]);
			}
			else
			{
				if(i&1)
				{
					minn=min(minn,pp[i-1]+post[i+1]);
				}
				else
				{
					minn=min(minn,pp[i-2]+post[i+2]+(a[i+1]-a[i-1]));
				}
			}
		}
		printf("%lld",minn);
	}
	else
	{
		for(int i=2;i<=k;i+=2)
		{
			res+=pre[i];
		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
1 2 3 4 5 6 7

*/