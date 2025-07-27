#include <stdio.h>
int main ()
{
	int n,i,max=0,min=100,k;
	double q;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k>max)
		max=k;
		if(k<min)
		min=k;
	}
	q=(max+min)*1.0/2;
	printf("%.2f",q);
	return 0;
}