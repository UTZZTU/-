#include <stdio.h>
int main ()
{
	int n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else  
		{
			sum=0;
		int c[1000];
		c[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]>c[i-1])
			{
				sum+=6*(c[i]-c[i-1]);
				sum+=5;
			}
			else if(c[i]<c[i-1])
			{
				sum+=4*(c[i-1]-c[i]);
				sum+=5;
			}
		}
		printf("%d\n",sum);
		}
		
	}
	return 0;
}
