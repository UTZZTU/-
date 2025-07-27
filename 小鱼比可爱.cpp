#include <stdio.h>
#include <string.h>
int main ()
{
	int n,a[105],b[105],i,j;
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	b[1]=0;
	for(j=2;j<=n;j++)
	{
		for(i=1;i<j;i++)
		{
			if(a[i]<a[j])
			b[j]++;
		}
	}
	for(i=1;i<=n;i++)
	printf("%d ",b[i]);
	return 0;
}