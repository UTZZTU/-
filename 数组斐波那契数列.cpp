#include <stdio.h>
int main ()
{
	int c[20]={1,1};
	for(int i=2;i<20;i++)
	{
		c[i]=c[i-1]+c[i-2];
	}
	for(int i=0;i<20;i++)
	{
		if(i%4==0)
		printf("\n");
		printf("%06d ",c[i]);
	}
	return 0;
}
