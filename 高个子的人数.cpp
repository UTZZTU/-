#include <stdio.h>
int main ()
{
	int n,a[10010],sum=0,i,t=0;
	double s;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	s=sum*1.0/n;
	for(i=0;i<n;i++)
	{
		if(a[i]>s)
		t++;
	}
	printf("%d",t);
	return 0;
}