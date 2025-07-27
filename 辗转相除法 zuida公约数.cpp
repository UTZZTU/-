#include <stdio.h>
int main ()
{
	int temp,a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	printf("%d\n",a);
	}
	return 0;
}
