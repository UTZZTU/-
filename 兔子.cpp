#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,i,a[21],x;
	long long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	sort(a+1,a+n+1);
	if(n%2==1)
	{
		x=a[n/2+1];
	}
	else
	{
		x=(a[n/2]+a[n/2+1])/2;
	}
	for(i=1;i<=n;i++)
	{
		if(x>=a[i])
		{
			sum+=x-a[i];
		}
		else
		{
			sum+=a[i]-x;
		}
	}
	printf("%lld",sum);
	return 0;
}
