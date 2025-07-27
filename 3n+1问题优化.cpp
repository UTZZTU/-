#include <stdio.h>
int c[10000001];
int fun(int a)
{
	int s=1,sum;
	c[0]=1;
	for(int i=2;i<=1000000;i++)
	{
		sum=1;
		while(i!=1)
		{
			if(i%2==0)
			{
				i=i/2;
				sum++;
			}
			else
			{
				i=(3*i+1)/2;
				sum+=2;
			}
		}
		c[s]=sum;
		s++;
	}
	return c[a-1];
}
int main ()
{
	long long int i,j,r;
	while(scanf("%d %d",&i,&j)!=EOF)
	{
	r=0;
		if(i>j)
		{
			for(int b=j;b<=i;b++)
			{
				if(fun(b)>r)
				r=fun(b);
			}
			printf("%d %d %d\n",i,j,r);
		}
		else if(i<=j)
		{
			
			for(int b=i;b<=j;b++)
			{
				if(fun(b)>r)
				r=fun(b);
			}
			printf("%d %d %d\n",i,j,r);
		} 
		
	}
	return 0;
}
