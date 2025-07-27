#include <stdio.h>
int main ()
{
	int t,n,w,sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=5;i<=20000;i=i*5)
		{
			w=n/i;
			sum+=w;
			
		}
		printf("%d\n",sum);
	}
	return 0;
}
