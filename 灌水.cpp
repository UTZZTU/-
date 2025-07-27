#include <stdio.h>
#define PI 3.14159
int main ()
{
	int h,r,w;
	double v;
	scanf("%d %d",&h,&r);
	v=PI*r*r*h;
	w=20000/v;
	printf("%d",w+1);
	return 0;
}
