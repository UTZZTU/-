#include <bits/stdc++.h>
using namespace std;
int t,f[100010],a[100010],n,u,v,len;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&u,&v);
			if(u==1&&v==0)
			{
				f[i]=1;
			}
			else if(u==0&&v==1)
			{
				f[i]=3;
			}
			else f[i]=2;
		}
		len=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&u);
			v=f[u];
			if(i==1)
			{
				len=1;
				a[len]=v;
			}
			else
			{
				if(v>=a[len])
				{
					a[++len]=v;
				}
				else
				{
					int pos=upper_bound(a+1,a+1+len,v)-a;
					a[pos]=v;
				}
			}
//			cout<<v<<endl;
		}
		cout<<n-len<<endl;
	}
	return 0;
}