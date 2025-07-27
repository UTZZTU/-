#include <stdio.h>
int fun1(int n,int m)
{	int t,max;
    if(n>m)
    {
    	t=n;
    	n=m;
    	m=t;
	}
	for(int i=1;i<=n;i++)
	{
		if(n%i==0&&m%i==0)
		max=i;
	}
	return max;
}
int fun2(int n,int m)
{	int t,min;
    if(n>m)
    {
    	t=n;
    	n=m;
    	m=t;
	}
	for(int i=m;i>1;i++)
	{
		if(i%n==0&&i%m==0)
		{
				min=i;
				break;
		}
	
	}
	return min;
}
int main ()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
	   printf("%d %d\n",fun1(n,m),fun2(n,m));
	}
	return 0;
}
