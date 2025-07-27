#include <stdio.h>
int fun(int z)
{
	int w=0;
	for(int i=2;i<z;i++)
	{
		if(z%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main ()
{
	int x,y,z;
	while(scanf("%d",&x)!=EOF)
	{
		if(x<6||x%2==1)
		printf("Error!\n");
		else
		{
			for(int y=2;y<=x/2;y++)
			{
				z=x-y;
				if(fun(y))
				{
					if(fun(z))
				{
					printf("%d=%d+%d\n",x,y,z);
				}
				}
			}
		}
	}
	return 0;
}
