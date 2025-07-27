#include <stdio.h>
int main ()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		if(m>=n)
		{
			int sum=0;
			for(int a=n;a<=m;a++)
			{
				if(a%15==0)
				{
					sum+=a;
				}
			}   printf("%d",sum);
		}  else
		{
			int mus=0;
			for(int b=m;b<=n;b++)
			{
				if(b%15==0)
				{
					mus+=b;
				}
			}   printf("%d",mus);
		}
		
		
	}
	return 0;
}
