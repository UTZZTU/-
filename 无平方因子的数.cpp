#include<stdio.h>
int main ()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long int w=2;
		if(n==1)
		printf("No\n");
		else
		{
		for(long long int i=2;i<n;i++)
		{
			if(n%(i*i)==0)
			{
				printf("Yes\n");
				break;
			}
			else w++;
		}
		if(w==n)
		{
			printf("No\n");
		}
	    }
	}
	return 0;
}
