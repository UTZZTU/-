#include <stdio.h>
int main ()
{
	int n,a,b;
	scanf("%d",&n);
	a=n/7;
	b=n%7;
	if(b==2)
	printf("%d",(a-1)*7+1);
	else if(b==1)
	printf("%d",(a-1)*7+2);
	else if(b==0)
	printf("%d",(a-1)*7+3);
	else if(b==6)
	printf("%d",a*7+4);
	else if(b==5)
	printf("%d",a*7+5);
	else if(b==4)
	printf("%d",(a-1)*7+6);
	else if(b==3)
	printf("%d",(a-1)*7);
	return 0;
}
