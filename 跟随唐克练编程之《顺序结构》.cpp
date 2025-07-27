#include <stdio.h>
#include <math.h>
int main ()
{
  int n,y,m,d;
  scanf("%d",&n);
  d=n/60/60/24;
  m=d/30;
  y=m/12;
  d=d%30;
  m=m%12;
  printf("%d %d %d",2011+y,1+m,1+d);
	return 0;
}
