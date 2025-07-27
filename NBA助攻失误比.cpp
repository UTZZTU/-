#include <stdio.h>
int main ()
{
	double s;
	int i=0,m,n,k1=0,k2=0;
	while(~scanf("%d%d",&m,&n))
	{
		i++;
		k1+=m;
		k2+=n;
	}
	printf("%d ",i);
	s=k1*1.0/k2;
	printf("%.1f",s);
	return 0;
}