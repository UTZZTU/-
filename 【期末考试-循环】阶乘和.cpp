#include <stdio.h>
int main ()
{
	int n,i,t,sum;
	while(scanf("%d",&n)!=EOF)
	{
		t=1;
		sum=0;
		for(i=2;i<=n;i++)
		{
			t*=i;
			if(i%2==0)
			sum+=t;
		}
		printf("%d\n",sum);
	}
	return 0;
}
