#include <stdio.h>
int main ()
{
	int m,n,t,a,b;
	scanf("%d%d",&m,&n);
	a=m;
	b=n;
	if(m<n)
	{
		t=m;
		m=n;
		n=t;
	}
	while(n!=0)
	{
		t=m%n;
		m=n;
		n=t;
	}
	printf("%d %d",m,a*b/m);
	return 0;
}