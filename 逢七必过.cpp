#include <stdio.h>
int main ()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		if(i%7==0||i%10==7)
		printf("pass\n");
		else
		printf("%d\n",i);
	}
}