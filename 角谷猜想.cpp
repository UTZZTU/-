#include <stdio.h>
int main ()
{
	int n,k,i;
	scanf("%d",&n);
	for(i=1;;i++)
	{
		if(n%2==0)
		{
			k=n/2;
			printf("%d/2=%d",n,k);
			if(k==1)
			break;
			else
			{
				printf("\n");
				n/=2;
			}
		}
		else
		{
			k=n*3+1;
			printf("%d*3+1=%d",n,k);
			if(k==1)
			break;
			else
			{
				printf("\n");
				n=n*3+1;
			}
		}
	}
	return 0;
}