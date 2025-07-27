#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int t;
double n,p1,v1,p2,v2,minn;
bool check(double x)
{
	double l1=max((x*v1-2*p1),(x*v1-p1)/2.0)+p1,l2=max((x*v2-2*(n-p2)),(x*v2-(n-p2))/2.0)+(n-p2);
	l2=n-l2;
	return l1>=l2;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		minn=20000000;
		scanf("%lf%lf%lf%lf%lf",&n,&p1,&v1,&p2,&v2);
		if(p1>p2)
		{
			swap(p1,p2);
			swap(v1,v2);
		}
		minn=min(minn,min((min(p1,n-p1)+n)*1.0/v1,(min(p2,n-p2)+n)*1.0/v2));
		minn=min(minn,max((n-p1)*1.0/v1,p2*1.0/v2));
		double l=max(p1*1.0/v1,(n-p2)*1.0/v2),r=minn;
//		cout<<minn<<endl;
		while(fabs(r-l)>eps)
		{
			double mid=(l+r)/2;
			if(check(mid)) r=mid,minn=min(minn,mid);
			else l=mid;
		}
		printf("%.10f\n",minn);
	}
	return 0;
}