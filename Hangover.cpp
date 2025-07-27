#include <stdio.h>
int main ()
{

	double n,s,sum;
	while(scanf("%lf",&n)!=EOF)
	{
		sum=0;
		if(n==0.00)
		break; 
		else
		{
		for(int i=1;i<=100000;i++)
		{
		s=1.0/(i+1);
		sum+=s;
			if(sum>=n)
			{
				printf("%d card(s)\n",i);
				break;
			}
		}
	}
	}
	return 0;
}
