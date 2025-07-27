#include <stdio.h>
#include <math.h>
# define q 6
struct cs
{
	int xs;
	int zs;
};
int main ()
{
	struct cs s[q]={{1,5
	},{4,4},{6,3},{10,2},{23,1},{100,0}};
	long long int n,sum,i;
	while(scanf("%lld",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<q;i++)
		{
			sum+=s[i].xs*pow(n,s[i].zs);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
