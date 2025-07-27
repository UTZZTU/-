#include <stdio.h>
int main ()
{
	int n,xs,i,j,a[105],pd=0;
	scanf("%d",&n);
	for(i=n;i>=0;i--)
	{
		scanf("%d",&a[i]);
	}
	for(i=n;i>=0;i--)
	{
		if(a[i]==0)
		continue;
		if(a[i]>0&&pd!=0)
		{
			printf("+");
		}
		if(a[i]<0)
		{
			printf("-");
			a[i]*=-1;
		}
		if(i==0)
		{
			printf("%d",a[i]);
		}
		else if(i==1)
		{
			if(a[i]==1)
			printf("x");
			else
			{
				printf("%dx",a[i]);
			}
		}
		else
		{
			if(a[i]==1)
			printf("x^%d",i);
			else
			{
				printf("%dx^%d",a[i],i);
			}
		}
		pd=1;
	}
	return 0;
 } 
