#include <stdio.h>
#define N 10
int main ()
{
	int fun(int a,int b,int c);
	int i,abc,def,ghi;
	for(i=111;i<=333;i++)
	{
		abc=i;
		def=2*i;
		ghi=3*i;
		if(fun(abc,def,ghi))
		{
			printf("%d %d %d\n",abc,def,ghi);
		}
	}
}
int fun(int a,int b,int c)
{
	int num[9],i=0,j;
	while(a!=0)
	{
		num[i]=a%10;
		a=a/10;
		i++;
	}
	while(b!=0)
	{
		num[i]=b%10;
		b=b/10;
		i++;
	}
	while(c!=0)
	{
		num[i]=c%10;
		c=c/10;
		i++;
	}
	for( i=0;i<8;i++)
	{
		for(j=i+1;j<9;)
		{
			if(num[i]!=num[j])
			j++;
			else
			return 0;
		}
	}
	return 1;
}
