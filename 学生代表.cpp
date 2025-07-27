#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,a[99],b[99],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		sort(a,a+n);
		b[i]=a[n/2];
	}
	sort(b,b+n);
	printf("%d",b[n/2]);
	return 0;
}
