#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b)
{
	int x,y,c;
	x=max(a,b);
	y=min(a,b);
	while(y!=0)
	{
		c=x%y;
		x=y;
		y=c;
	}
	return x;
}
int main ()
{
	int n,a[55],i,j,sum=0;
	double pi;
	while(~scanf("%d",&n))
	{
		sum=0;
		if(n==0)
		break;
		else
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
			}
			for(i=1;i<=n-1;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					if(gcd(a[i],a[j])==1)
					sum++;
				}
			}
			if(sum==0)
			printf("No estimate for this data set.\n");
			else
			{
				pi=sqrt(3*n*(n-1)*1.0/sum);
				printf("%.6f\n",pi);
			}
		}
	}
	return 0;
}