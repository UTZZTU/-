#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int a[55],i,l=0,k,n;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=n,k;i>=1&&k>0;i--,k--)
	l+=a[i];
	printf("%d",l);
	return 0;
}
