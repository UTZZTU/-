#include <bits/stdc++.h>
using namespace std;
int t,l,r,m,x,sum,tl,tr,px,py;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&x);
			sum=r-l+1;
			tl=l/x,tr=r/x;
			if(tl!=tr)
			{
				sum-=(tr-ceil(l*1.0/x))*x+1;
				sum-=2*min(r-tr*x,ceil(l*1.0/x)*x-l);
				if(r-tr*x<=ceil(l*1.0/x)*x-l)
				{
					r=ceil(l*1.0/x)*x-(r-tr*x);
					tr=ceil(r*1.0/x);
					px=floor((tr*x+tl*x)*1.0/2);
					py=ceil((tr*x+tl*x)*1.0/2);
					if(l<=px&&r>=)
				}
				else
				{
					l=r-ceil(l*1.0/x)*x;
				}
			}
			else
			{
				
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}