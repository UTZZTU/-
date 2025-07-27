#include <stdio.h>
int main ()
{
	long long int c,n,q,w,s,t;
	scanf("%lld",&c);
	while(c--)
	{
		scanf("%lld",&n);
		if(n==2)
		printf("50.00%%\n");
		else
		{
			q=0;
			w=1;
			t=1;
			for(int i=3;i<=n;i++)
			{
				s=(i-1)*(w+q);
				q=w;
				w=s;
			}
			for(int i=2;i<=n;i++)
			{
				t*=i;
			}
			double r;
			r=s*1.0/t;
			printf("%.2f%%\n",r*100);
		}
	}
	return 0;
}
