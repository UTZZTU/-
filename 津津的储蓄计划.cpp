#include <stdio.h>
int main ()
{
	int a[13],i,m=0,pd=0,z=0,k;
	for(i=1;i<=12;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=12;i++)
	{
		z+=300;
		if(z>=a[i])
		{
			k=(z-a[i])/100;
			if(k>0)
			{
				m+=k*100;
				z-=k*100;
			}
			z-=a[i];
		}
		else
		{
			printf("-%d",i);
			pd=1;
			break;
		}
	}
	m*=1.2;
	if(pd==0)
	{
		printf("%d",z+m);
	}
	return 0;
}