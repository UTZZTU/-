#include <stdio.h>
#include <math.h>
int main ()
{
	int a,b,c,d,n;
	scanf("%d",&n);
	for(a=1;a<=floor(sqrt(n));a++)
	{
		for(b=0;b<a;b++)
		{
			for(c=0;c<b;c++)
			{
				for(d=0;d<c;d++)
				{
					if(a*a+b*b+c*c+d*d==n)
					{
						if(b==0)
						{
							printf("%d=%d*%d\n",n,a,a);
						}
						else if(c==0)
						{
							printf("%d=%d*%d+%d*%d\n",n,a,a,b,b);
						}
						else if(d==0)
						{
							printf("%d=%d*%d+%d*%d+%d*%d\n",n,a,a,b,b,c,c);
						}
						else
						printf("%d=%d*%d+%d*%d+%d*%d+%d*%d\n",n,a,a,b,b,c,c,d,d);
					}
				}
			}
		}
	}
}