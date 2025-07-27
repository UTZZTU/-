#include <stdio.h>
int main ()
{
	int n,a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		double x;
		a=0;
		b=0;
		c=0;
		if(n==0)  break;
		else 
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%lf",&x);
				if(x<0)
				{
					a++;
				}
				else if(x==0)
				{
					b++;
				}
				else
				{
					c++;
				}
			}printf("%d %d %d\n",a,b,c);
		}
			
		
	}
	return 0;
}
