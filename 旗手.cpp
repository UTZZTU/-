#include <stdio.h>
int main ()
{
	int n,a[10010],t=0,i,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>t)
		{
			t=a[i];
			m=i;
		}
	}
	i=a[0];
	a[0]=t;
	a[m]=i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}