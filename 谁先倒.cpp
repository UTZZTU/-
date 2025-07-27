#include <stdio.h>
int main ()
{
	int sum1,sum2,a1,a2,b1,b2,k1,k2,n,h1=0,h2=0;
	scanf("%d%d",&sum1,&sum2);
	scanf("%d",&n);
	k1=sum1;
	k2=sum2;
	while(n--)
	{
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		if(b1==a1+a2&&b2==a1+a2)
		continue;
		if(b1==a1+a2)
		{
			k1--;
			h1++;
			if(k1<0)
		{
			printf("A\n");
			printf("%d",h2);
			break;
		}
		}
		if(b2==a1+a2)
		{
			k2--;
			h2++;
			if(k2<0)
		{
			printf("B\n");
			printf("%d",h1);
			break;
		}
		}
	}
	return 0;
}