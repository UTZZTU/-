#include <stdio.h>
int main ()
{
	int m,n;
	scanf("%d %d",&m,&n);
	if(m>=n)
	{
		for(int i=1500-m;i<=1500-n;i++)
		{
			if(i%3==2&&i%5==4&&i%7==6)
			printf("%d\n",i);
		}
	}
	else
	{
		for(int i=1500-n;i<=1500-m;i++)
		{
			if(i%3==2&&i%5==4&&i%7==6)
			printf("%d\n",i);
		}
	}
	return 0;
}
