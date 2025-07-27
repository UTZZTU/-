#include <stdio.h>
int main ()
{
	int n,k,i,n1=0,n2=0,sum1=0,sum2=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k>0)
		{
			n1++;
			sum1+=k;
		}
		else if(k<0)
		{
			n2++;
			sum2+=k;
		}
	}
	printf("%d %d\n%d %d",n1,sum1,n2,sum2);
	return 0;
}