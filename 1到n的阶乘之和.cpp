#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n); 
long long int sum=0;
	for(int i=1;i<=n;i++)
	{
		long long int s=1;
		for(int a=1;a<=i;a++)
		{
			s*=a;
		}
		sum+=s; 
	}
	printf("%lld",sum); 
	return 0;
}
