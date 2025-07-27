#include <stdio.h>
int main ()
{
	int a,b,c;
	for(int a=0;a<=100;a++)
	{
		for(int b=0;b<=100;b++)
		{
			for(int c=0;c<=100;c++)
			{
				if(a*5+b*3+c*1.0/3==100&&a+b+c==100)
				printf("%d %d %d\n",a,b,c);
			}
		}
	}
	return 0;
}
