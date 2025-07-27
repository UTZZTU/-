#include <stdio.h>
int main ()
{
	int t,sum,q,h,i,k=1;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&q,&h);
		sum=0;
		k=1;
		while(q!=0)
		{
			sum+=(q%10)*k;
			k*=2;
			q/=10;
		}
		printf("%d",sum*h);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
