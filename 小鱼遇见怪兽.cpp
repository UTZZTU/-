#include <stdio.h>
int main ()
{
	int x,n,m;
	scanf("%d%d%d",&x,&m,&n);
	m-=3*x;
	n-=x;
	if(2*n-m<0||(2*n-m)%3!=0||4*m-5*n<0||(4*m-5*n)%6!=0)
	printf("No Answer");
	else
	printf("%d %d",(4*m-5*n)/6,(2*n-m)/3);
	return 0;
}