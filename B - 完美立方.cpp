#include <stdio.h>
int main ()
{
	int n,a,b,c,d;
	scanf("%d",&n);
	for(a=2;a<=n;a++)
	{
		for(b=2;b<=n;b++)
		{
			for(c=b;c<=n;c++)
			{
				for(d=c;d<=n;d++)
				{
					if(a*a*a==b*b*b+c*c*c+d*d*d)
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					}
				}
			}
		}
	}
	return 0;
}
