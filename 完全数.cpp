#include <stdio.h>
int fun(int n)
{
	int i,sum=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		sum+=i;
	}
	if(sum==n)
	return 1;
	else
	return 0;
}
int main ()
{
	int x,y,i,sum=0,a[10000],m;
	scanf("%d%d",&x,&y);
	m=0;
	for(i=x;i<=y;i++)
	{
		if(fun(i))
		{
			sum++;
			a[m]=i;
			m++;
		}
	}
	if(sum==0)
	printf("no");
	else
	{
		for(i=0;i<m-1;i++)
		{
			printf("%X ",a[i]);
		}
		printf("%X",a[i]);
	}
	return 0;
}
