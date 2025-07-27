#include <stdio.h>
int main ()
{
	int n,t,sum;
	while(scanf("%d",&n)!=EOF)
	{
		if(n%100==0)
		{
			printf("0\n");
		}
		else
		{
			sum=0;
			t=(n/100+1)*100;
			t=t-n;
			if(t>=50)
			{
				sum+=t/50;
				t%=50;
			}
			if(t>=20)
			{
				sum+=t/20;
				t%=20;
			}
			if(t>=10)
			{
				sum+=t/10;
				t%=10;
			}
			if(t>=5)
			{
				sum+=t/5;
				t%=5;
			}
			if(t>=1)
			{
				sum+=t/1;
				t%=1;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
