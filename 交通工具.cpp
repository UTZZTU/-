#include <stdio.h>
#include <math.h>
int main ()
{
	int n,n1,n2;
	double m1,m2,m3,q1,q2;
	while(~scanf("%d %lf %lf %lf",&n,&m1,&m2,&m3))
	{
		q2=m3;
		if(n>=1&&n<=5)
		q1=m1+m2;
		else if(n>=6&&n<=10)
		q1=m1*0.6+m2;
		else if(n>=11&&n<=20)
		q1=m1*0.5+m2;
		else if(n>=21&&n<=31)
		q1=m1*0.3+m2;
		n1=floor(q1+0.5);
		n2=floor(q2+0.5);
		if(n1<n2)
		printf("Airplane %d\n",n1);
		else
		printf("Train %d\n",n2);
	}
	return 0;
}