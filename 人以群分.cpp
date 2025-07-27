#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,sum=0,pj,i,a[100100],s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	pj=n/2;
	sort(a+1,a+1+n);
	for(i=1;i<=pj;i++)
	{
		s+=a[i];
	}
	printf("Outgoing #: %d\n",n-pj);
	printf("Introverted #: %d\n",pj);
	printf("Diff = %d",sum-s-s);
	return 0;
}