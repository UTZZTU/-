#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,x,y,p[200010];
double f1[200010],f2[200010];
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&x,&y);
		double res=0,maxx1=0,maxx2=0;
		int pos1=-1,pos2=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&p[i]);
			res+=p[i];
		}
		for(int i=1;i<=n;i++)
		{
			f1[i]=(double)p[i]*1.0-p[i]*x/100.0;
			f2[i]=(double)min(y,p[i]);
			if(f1[i]>maxx1)
			{
				maxx1=f1[i];
				pos1=i;
			}
			if(f2[i]>maxx2)
			{
				maxx2=f2[i];
				pos2=i;
			}
		}
		maxx1=maxx2=0;
		for(int i=1;i<=n;i++)
		{
			if(i!=pos1)
			{
				maxx2=max(maxx2,f2[i]);
			}
			if(i!=pos2)
			{
				maxx1=max(maxx1,f1[i]);
			}
		}
		printf("%.10f\n",min(res-f1[pos1]-maxx2,res-f2[pos2]-maxx1));
	}
	return 0;
}