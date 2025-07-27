#include <stdio.h>
int fun(int a,int b)
{
	int t;
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main ()
{
	int m,n,t,i,min,max;
	scanf("%d%d",&m,&n);
	if(m<=n)
	{
		t=m;
		m=n;
		n=t;
	}
	min=fun(m,n);
	max=m/min*n;
	printf("the greatest common divisor is %d\n",min);
	printf("the least common multiple is %d",max);
	return 0;
 } 
