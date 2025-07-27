#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main ()
{
	int k,i,a[15],z,n,sum=0;
	scanf("%d",&k);
	n=ceil(k*1.0/2);
	for(i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+k);
	for(i=0;i<n;i++)
	{
		sum+=ceil(a[i]*1.0/2);
	}
	printf("%d",sum);
	return 0;
}
