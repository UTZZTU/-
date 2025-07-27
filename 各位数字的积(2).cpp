#include <stdio.h>
#include <math.h>
int main ()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int w,sum=1,q,s;
		for(int i=1;i<=8;i++)
		{
			q=pow(10,i);
			w=n%q/pow(10,i-1);
			sum*=w;
			s=n/q;
			if(s==0)
			break;
		}
		printf("%d\n",sum);
	}
	return 0;
}
