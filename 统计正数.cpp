#include <stdio.h>
int main ()
{
	int a,sum=0;
	while(~scanf("%d",&a))
	{
		if(a==0)
		break;
		else
		{
			if(a>0)
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}