#include <stdio.h>
#include <math.h>
int main ()
{
	int n,m,q,h,i,pd=0;
	scanf("%d",&n);
	h=n;
	for(i=1;i<=50000;i++)
	{
		q=pow(h%10,3)+pow(h/10%10,3)+pow(h/100%10,3);
		if(q==h)
		{
			pd=1;
			break;
		}
		h=pow(q%10,3)+pow(q/10%10,3)+pow(q/100%10,3);
		if(q==h)
		{
			pd=1;
			break;
		}
	}
	if(pd==1)
	printf("%d",q);
	else
	printf("error");
	return 0;
}
