#include <stdio.h>
#include <math.h>
int main ()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long int w=2;
		 long long s;
		s=sqrt(n);
		for(long long int i=2;i<=s;i++) 
		{
			if(n%i==0)
			{
				printf("No\n");
				break;
			}
			else w++;
		}
		if(w==s+1)
		printf("Yes\n");
		
	}
		return 0;
}

