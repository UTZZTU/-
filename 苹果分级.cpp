#include <stdio.h>
int main ()
{
	int n,n1=0,n2=0,n3=0,n4=0,sum=0;
	while(~scanf("%d",&n))
	{
		if(n<20)
		break;
		else
		{
			sum++;
			if(n>=70)
			n1++;
			else if(n<=69&&n>=60)
			n2++;
			else if(n<=59&&n>=50)
			n3++;
			else
			n4++;
		}
	}
	printf("%d\n",sum);
	printf("%d %d %d %d",n1,n2,n3,n4);
}