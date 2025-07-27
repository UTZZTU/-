#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a,b,x,y;
double p[200010],p1[200010],p2[200010],p3[200010],minn,sum;
bool cmp(double x,double y)
{
	return x>y;
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		
		minn=923456789000;
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&x,&y);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&p[i]);
		}
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			p1[i]=p1[i-1]+p[i];
			p2[i]=p2[i-1]+p[i]*x/100.0;
			p3[i]=p3[i-1]+max(p[i]-(double)y,0.0);
		}
		for(int i=0;i<=a;i++)
		{
			sum=0;
			sum+=p2[i];
			int cc1=min(i+b,n);
			sum+=p3[cc1]-p3[i];
			int cc2=min(a+b,n);
			sum+=p2[cc2]-p2[cc1];
			sum+=p1[n]-p1[cc2];
			minn=min(minn,sum);
		}
		printf("%.10f\n",minn);
	}
	return 0;
}