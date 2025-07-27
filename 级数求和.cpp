#include <stdio.h>
int main ()
{
	int k,i;
	scanf("%d",&k);
	double s=0,q;
	for(i=1;;i++)
	{
		q=1.0/i;
		s+=q;
		if(s>k)
		break;
	}
	printf("%d",i);
	return 0;
}