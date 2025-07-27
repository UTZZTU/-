#include <stdio.h>
#include <math.h>
int main ()
{
	int r,m,y,d=0;
	double s,q;
	scanf("%d%d%d",&r,&m,&y);
	s=m;
	q=1+r*1.0/100;
	while(s<=y)
	{
		d++;
		s*=q;
	}
	printf("%d",d);
	return 0;
}