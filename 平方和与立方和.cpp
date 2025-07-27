#include <stdio.h>
int main ()
{
	int m,n,x,y;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		x=0;
		y=0;
		if(m>=n)
		{
			for (int i=n;i<=m;i++)
			{
				if(i%2==0)
				{
					x+=i*i;
				}
				else 
				y+=i*i*i;
			}
			printf("%d %d\n",x,y);
		}
		else
		{
			for (int i=m;i<=n;i++)
			{
				if(i%2==0)
				{
					x+=i*i;
				}
				else 
				y+=i*i*i;
			}
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}
