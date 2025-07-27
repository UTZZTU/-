#include <stdio.h>
int main ()
{
	long long int a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		long long int s;
		s=b-a;
		if(s>=0)
		printf("%lld\n",s);
		else printf("%lld\n",-s);
	}
	return 0;
}
