#include <stdio.h>
#include <math.h>
int main ()
{
	int a,b,c,d,e;
	double f;
    int w[110];
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if(a==0&&b==0&&c==0)
		{
			break;
		}
		else 
		{
			f=a;
			d=a/b;
			printf("%d",d);
			if(c>0)
			{
					printf(".");
			for(int i=1;i<=c;i++)
			{
				
			    e=f*10/b;
			    f=f*10-b*e;
			    if(i==c&&e>=5)
			    {
			    	e=e+1;
				}
				printf("%d",e);
			}
			}
				printf("\n");
		}
	}
	return 0;
}
