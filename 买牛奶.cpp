#include <stdio.h>
#include <math.h>
int main ()
{
    int m,n,a,b;
    scanf("%d%d",&m,&n);
    a=(n-2*m)/2;
    b=2*m-n/2;
    printf("rabbit=%d,chicken=%d",a,b);
	return 0;
 } 
