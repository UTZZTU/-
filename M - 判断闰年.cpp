#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	if(n%4!=0)
	printf("N");
	else
	{
		if(n%100==0&&n%400!=0||n%3200==0)
		printf("N");
		else
		printf("Y");
	}
	return 0;
 } 
