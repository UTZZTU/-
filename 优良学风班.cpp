#include <stdio.h>
int main ()
{
	int n,i,k,sum1=0,sum2=0;
	double r1,r2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k>=60)
		sum1++;
		if(k>=80)
		sum2++;
	}
	r1=sum1*1.0/n;
	r2=sum2*1.0/n;
	if(r1>=0.95&&r2>=0.6)
	printf("Yes");
	else
	printf("No");
	return 0;
}