#include <stdio.h>
int main ()
{
	int m,n,i,s=0;
	scanf("%d %d",&m,&n);
if(m>=n)
{
	for(i=1;i<=n;i++)
	{
		if(m%i==0&&n%i==0)
		{
			if(i>s)
			s=i;
		}
	}
	printf("%d ",s);
	for(i=m;i>=m;i++)
	{
		if(i%m==0&&i%n==0)
		{
			printf("%d",i);
			break;
		}
	}
}
else
{
	for(i=1;i<=m;i++)
	{
		if(m%i==0&&n%i==0)
		{
			if(i>s)
			s=i;
		}
	}
	printf("%d ",s);
	for(i=n;i>=n;i++)
	{
		if(i%m==0&&i%n==0)
		{
			printf("%d",i);
			break;
		}
	}
}
	return 0;
}
