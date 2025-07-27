#include <stdio.h>
int main ()
{
	int t;
		scanf("%d",&t);
		if(t%2==1)
		printf("0 0");
		else
		{
			if(t%4==0)
			printf("%d %d",t/4,t/2);
			else
			printf("%d %d",t/4+1,t/2);
		}
	return 0;
}
