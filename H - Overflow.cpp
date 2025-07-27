#include <iostream>
using namespace std;
typedef long long ll;
ll t,n;
double l[100010],p[100010],eps=1e-5,sum,s,h,v;
bool check(double x)
{
//	double sum=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(p[i]<1) sum+=p[i]*l[i]*l[i]*l[i];
//		else sum+=min((double)h,l[i])*l[i]*l[i];
//	}
	return v+sum<x*s;
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&l[i],&p[i]);
		}
		scanf("%lf%lf%lf",&s,&h,&v);
		for(int i=1;i<=n;i++)
		{
			if(p[i]<1) sum+=p[i]*l[i]*l[i]*l[i];
			else sum+=min((double)h,l[i])*l[i]*l[i];
		}
		double left=v*1.0/s,right=h,mid;
		while(right-left>eps)
		{
			mid=(left+right)/2.0;
			if(check(mid)) right=mid;
			else left=mid;
		}
		printf("%.2f\n",left);
	}
	return 0;
}