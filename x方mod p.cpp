#include <stdio.h>
int main ()
{
	long long int x,p,a,w=1;
	scanf("%lld %lld",&p,&a);
	for(x=1;x<=p;x++)
	{
		if((x*x)%p==a)
		{
			printf("%d ",x);
		}
		else   w++;
	}
	if(w==p+1)
	printf("No Solution");
	return 0;
}
