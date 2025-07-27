#include <stdio.h>
int main ()
{
int m,n,s,w;
scanf("%d %d",&m,&n);
if(m>=n)
{
	for (int i=1;i<=n;i++)
	{
		if(m%i==0&&n%i==0)
		s=i;
	}
	for(int i=m;i>0;i++)
	{
		if(i%m==0&&i%n==0)
		{
			w=i;
			break;
		}
	}
	printf("%d %d",s,w);
}
else
{
	for (int i=1;i<=m;i++)
	{
		if(m%i==0&&n%i==0)
		s=i;
	}
	for(int i=n;i>0;i++)
	{
		if(i%m==0&&i%n==0)
		{
			w=i;
			break;
		}
	}
	printf("%d %d",s,w);
}
	return 0;
}
