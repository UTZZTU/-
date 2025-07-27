#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	long long int n,a[10010],i,sum=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	sum+=i*a[i];
	printf("%lld",sum);
	return 0;
}