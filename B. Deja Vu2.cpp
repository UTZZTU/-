#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,q,a[100010],x[100010],f[100010],pre[50],post[50],sum[100010];
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			int j=a[i],cnt=0;
			while(j%2==0)
			{
				j/=2;
				cnt++;
			}
			f[i]=cnt;
		}
		memset(pre,-1,sizeof pre);
		memset(post,-1,sizeof post);
		for(int i=1;i<=q;i++)
		{
			scanf("%lld",&x[i]);
			sum[i]=pow(2,x[i]-1);
			if(pre[x[i]]==-1) pre[x[i]]=i;
		}
		for(int i=q;i>=1;i--)
		{
			int idx=-1;
			for(int j=1;j<x[i];j++)
			{
				if(post[j]==-1) continue;
				if(idx==-1)
				{
					idx=post[j];
				}
				else idx=min(idx,post[j]);
			}
			if(idx!=-1) sum[i]+=sum[idx];
			post[x[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(!f[i]) printf("%lld ",a[i]);
			else
			{
				int idx=-1;
				for(int j=1;j<=f[i];j++)
				{
					if(pre[j]==-1) continue;
					if(idx==-1)
					{
						idx=pre[j];
					}
					else idx=min(idx,pre[j]);
				}
				if(idx!=-1) printf("%lld ",a[i]+sum[idx]);
				else printf("%lld ",a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}