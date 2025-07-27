#include <stdio.h>
int main ()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		double w,sum=0;
		scanf("%d %d",&n,&m);
		for(int i=n;i<=m;i++)
		{
			w=1.0/(i*i);
			sum+=w;
		}
		printf("%.5f\n",sum);
	}
	return 0;
}
