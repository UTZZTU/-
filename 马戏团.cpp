#include <stdio.h>
int main ()
{
	int n,a,b,c,pd=0;
	scanf("%d",&n);
	for(a=0;a<=24;a++)
	{
		for(b=0;b<=60;b++)
		{
			c=n-a-b;
			if(c>=0)
			{
				if(a*5+b*2+c*0.1==120)
			{
				printf("%d %d %d\n",a,b,c);
				pd=1;
			}
			}
		}
	}
	if(pd==0)
	printf("No output");
	return 0;
}
