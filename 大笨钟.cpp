#include <stdio.h>
int main ()
{
	int q,h,i,sum;
	scanf("%d:%d",&q,&h);
	if(q<=11||q==12&&h==0)
	printf("Only %02d:%02d.  Too early to Dang.",q,h);
	else
	{
		sum=q-12;
		if(h>0)
		sum++;
		for(i=1;i<=sum;i++)
		printf("Dang");
	}
	return 0;
}