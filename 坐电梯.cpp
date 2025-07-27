#include <stdio.h>
int main ()
{
	int n,i,a=0,x,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>=a)
		{
			sum+=6*(x-a);
			sum+=5;
			a=x;
		}
		else
		{
			sum+=4*(a-x);
			sum+=5;
			a=x;
		}
	}
	printf("%d",sum);
	return 0;
}
