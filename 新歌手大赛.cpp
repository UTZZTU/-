#include <stdio.h>
int main ()
{
	int a,n;
	while(scanf("%d",&a)!=EOF)
	{
		int min=0,max=100;
		double sum=0;
		int c[10];
		c[0]=a;
		for(int i=1;i<=9;i++)
		{
			scanf("%d",&n);
			c[i]=n;
			sum+=c[i];
		}
		sum=sum+c[0];
		for(int i=0;i<=9;i++)
		{
			if(c[i]>min)
			min=c[i];
			if(c[i]<max)
			max=c[i];
		}
		sum=sum-max-min;
		sum=sum/8;
		printf("%.2f\n",sum);
	}
	return 0;
}
