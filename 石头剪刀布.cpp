#include <stdio.h>
int main ()
{
	int n,x,y,i,sum1=0,sum2=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			sum1++;
			sum2++;
		}
		else
		{
			if(x==0&&y==1)
			sum1+=2;
			else if(x==0&&y==2)
			sum2+=2;
			else if(x==1&&y==0)
			sum2+=2;
			else if(x==1&&y==2)
			sum1+=2;
			else if(x==2&&y==0)
			sum1+=2;
			else if(x==2&&y==1)
			sum2+=2;
		}
	}
	printf("%d %d",sum1,sum2);
	return 0;
}