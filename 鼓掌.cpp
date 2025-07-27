#include <stdio.h>
int fun(int a,int b)
{
	int t;
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main ()
{
	int x,y,n,a,b,c,t;
	scanf("%d%d%d",&x,&y,&n);
	if(x<=y)
	{
		t=y;
		y=x;
		x=t;
	}
		a=n/x;
		b=n/y;
		c=x/fun(x,y)*y;
		c=n/c;
		printf("%d",a+b-c);
	return 0;
}
