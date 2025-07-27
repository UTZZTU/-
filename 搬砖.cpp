#include <stdio.h>
int main ()
{
	int a,b,c;
	for(int a=0;a<=36;a++)
	{
		for(int b=0;b<=36;b++)
		{
			for(int c=0;c<=36;c++)
			{
				if(4*a+3*b+0.5*c==36&&a+b+c==36)
				printf("%d %d %d",a,b,c);
			}
		}
	}
	return 0;
}
