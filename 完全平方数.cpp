#include <stdio.h>
#include <math.h>
int fun(int p)
{
	if(p==2||p==3)
	{
		return 1;
	}
	if(p%6!=1&&p%6!=5)
	{
		return 0;
	}
	for(int i=5;i<=floor(sqrt(p));i+=6)
	{
		if(p%i==0||p%(i+2)==0)
		{
			return 0;
		}
	}
	return 1;
}
int main ()
{
	int m,n,i,sum=0;
	scanf("%d%d",&m,&n);
	for(i=33;i<=100;i++)
	{
		if(i*i>=m&&i*i<=n&&(i*i)%10==4)
		{
			if(fun(i*i-45))
			{
				printf("%d\n",i*i);
				sum++;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
