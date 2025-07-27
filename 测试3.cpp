#include <stdio.h>
int main ()
{
	long int n;
	while (scanf("%ld",&n)!=EOF)
	{
	long int s;
		if (n==0)
		break;
		else
		{
			if(n==1)
			printf("1");
			else if(n==2)
			printf("2");
			else if(n==3)
			printf("3");
			else if(n==4)
			printf("4");
			else if(n==5)
			printf("5");
			else 
			{
				for(long int i=6;i<=999999;i++)
				{
					if(i%4==0||i%6==0||i%10==0||i%9==0||i%15==0||i%25==0)
					{
						if (i>=n)
						{
							printf("%d\n",i);
							break;
						}
					}
				}
				
			}
		}
	}
	return 0;
}
