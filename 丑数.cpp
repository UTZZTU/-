#include <stdio.h>
int main ()
{
	long int n;
	while (scanf("%ld",&n)!=EOF)
	{
	long int s,w=0;
		if (n==0)
		break;
		else
		{
			if(n==1)
			printf("1");
			else 
			{
				for(long int i=1;i<=999999;i++)
				{
					if(i%2==0||i%3==0||i%5==0)
					{
						s=i;
						w++;
						
					}
					if(w==n-1)
						break;
				}
				printf("%ld\n",s);
			}
		}
	}
	return 0;
}
