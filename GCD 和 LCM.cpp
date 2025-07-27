#include <stdio.h>
int calculate (int a,int b)
{
	int temp;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return (a);
}
int main ()
{
	int a,b,max,min,x,d;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a>=b)
		{
			max=a;
			min=b;
		}
		else
		{
			max=b;
			min=a;
		}
		x=calculate(max,min);
		d=max/x*min;
		printf("%d %d\n",x,d);
	}
	return 0;
}
