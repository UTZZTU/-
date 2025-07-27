#include <stdio.h>
int main ()
{
    int s,a,b,c,d;
    scanf("%d",&s);
    a=s/86400;
    b=s%86400/3600;
	c=s%86400%3600/60;
	d=s%86400%3600%60;
	printf("%02d %02d:%02d:%02d",a,b,c,d);
	return 0;
}
