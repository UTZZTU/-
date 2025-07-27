#include <stdio.h>
#include <math.h>
int main ()
{
	int x,i,jc=1;
	double sum=1,t,b;
	scanf("%d",&x);
	for(i=1;;i++)
	{
		jc*=i;
		t=pow(x,i)*1.0/jc;
		if(b-t<pow(10,-8))
		break;
		else
		{
			sum+=t;
			b=t;
		}
	}
	printf("%.8f",sum);
	return 0;
}
