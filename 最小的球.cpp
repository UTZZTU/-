#include <stdio.h>
int main ()
{
	int n,i;
	double s=41,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&t);
		if(t<s)
		s=t;
	}
	printf("%.2f",s);
	return 0;
}
