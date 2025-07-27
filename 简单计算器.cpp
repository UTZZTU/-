#include <stdio.h>
int main ()
{
	int n;
	double a,b,sum;
	char c;
	scanf("%lf%c%lf",&a,&c,&b);
	n=c;
	switch(n)
	{
		case 43:
		    sum=a+b;
		    break;
	    case 45:
	    	sum=a-b;
			break;
		case 42:
		    sum=a*b;
			break;
		case 47:
		    sum=a/b;
			break;  
	}
	printf("%.6f",sum);
	return 0;
 } 
