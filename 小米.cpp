#include <stdio.h>
int main ()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c==1)
	printf("%d",(a+b+13)/2);
	else
	printf("%d",(a+b-13)/2);
	return 0;
}