#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
int t;
double px,py,ax,ay,bx,by;
bool check(double rx1,double px1,double rx2,double px2,double r)
{
	return (double)sqrt((rx1-rx2)*(rx1-rx2)+(px1-px2)*(px1-px2))<=r;
}
bool judge(double x)
{
	if(check(0L,0L,ax,ay,x)&&check(px,py,ax,ay,x)) return true;
	if(check(0L,0L,bx,by,x)&&check(px,py,bx,by,x)) return true;
	if((check(0L,0L,ax,ay,x)||check(0L,0L,bx,by,x))&&(check(px,py,ax,ay,x)||check(px,py,bx,by,x))&&check(ax,ay,bx,by,2*x)) return true;
	return false;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&px,&py,&ax,&ay,&bx,&by);
		double l=0,r=10000;
		while(r-l>eps)
		{
			double mid=(l+r)/2.0;
			if(judge(mid)) r=mid;
			else l=mid;
		}
		printf("%.10f\n",l);
	}
	return 0;
}