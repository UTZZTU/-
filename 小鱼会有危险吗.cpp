#include <stdio.h>
int main ()
{
	double s,x,sum=0,q;
	int pd=0;
	scanf("%lf %lf",&s,&x);
	q=7;
	while(sum<=s+x)
	{
		sum+=q;
		q*=0.98;
		if(sum>=s-x)
		{
			if(sum+q<=s+x)
			{
				printf("y");
				pd=1;
				break;
			}
			else
			break;
		}
	}
	if(pd==0)
	printf("n");
	return 0;
}