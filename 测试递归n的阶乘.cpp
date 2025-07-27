#include <stdio.h>
#include <stdlib.h> 
int fun(int n)
{
	float t;
	if(n<0)
	{
		printf("error");
		exit(-1);
	}
	else if(n==0||n==1)
	{
		t=1;
	}
	else  t=n*fun(n-1);
	return t;
}
int main ()
{
	int n;
	float y;
	while(scanf("%d",&n)!=EOF)
	{
		y=fun(n);
		printf("%d!=%.0f\n",n,y);
	}
	return 0;
}
