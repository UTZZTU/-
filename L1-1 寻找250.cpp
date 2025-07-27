#include <stdio.h>
int main ()
{
	int k,pd=0,i=1;
	while(~scanf("%d",&k))
	{
		if(k!=250&&pd==0)
		{
			i++;
		}
		else
		{
			pd=1;
		}
	}
	printf("%d",i);
	return 0;
}