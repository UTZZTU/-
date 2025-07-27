#include <stdio.h>
int main ()
{
	int n,i=0,k,y;
	scanf("%d",&n);
	k=n;
	while(k!=0)
	{
		i++;
		k/=10;
	}
	if(i<=4)
	{
		y=n%100;
		n/=100;
		if(n<22)
		n+=20*100;
		else
		n+=19*100;
	}
	else
	{
		y=n%100;
		n/=100;
	}
	printf("%04d-%02d",n,y);
	return 0;
}