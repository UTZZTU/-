#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,i;
	long long int sum=0,b[100010],z=0,a[100010];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		sum+=a[i];
		b[i]=sum;
	}
	for(i=n;i>1;i--)
	{
		sum=(i-1)*a[i]-b[i-1];
		z+=sum;
	}
	printf("%lld",z);
	return 0;
}
