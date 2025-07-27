#include <stdio.h>
int main ()
{
	long long int s,d;
	while (scanf("%lld %lld",&s,&d)!=EOF)
	{
		long long int w=d,m=0,t;
		for(int i=s;i<=10000000000000;i++)
		{
			w=w-i;
			
			if(w<=0)
			{
				break;
			}
			m++;
		}
		t=s+m;
		printf("%lld\n",t);
	}
	return 0;
}
