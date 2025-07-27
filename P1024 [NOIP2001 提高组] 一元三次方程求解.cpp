#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double fun(double n)
{
	return a*n*n*n+b*n*n+c*n+d;
}
int main ()
{
	double l,r,mid;
	int s=0;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	for(int i=-100;i<100;i++)
	{
		l=i;
		r=i+1;
		double tl,tr,tm;
		tl=fun(l);
		tr=fun(r);
		if(tl==0)
		{
			printf("%.2f ",l);
			s++;
		}
		else if(tl*tr<0)
		{
			s++;
			while(r-l>=0.001)
			{
				mid=(r+l)*1.0/2;
				tm=fun(mid);
				if(tm*tr<=0)
				l=mid;
				else
				r=mid;
			}
			printf("%.2f ",l);
		}
		if(s==3)
		break;
	}
	return 0;
}