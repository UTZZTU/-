#include<stdio.h>
#include <string.h>
int main ()
{
	int n,i,a[5050],k,max=0,min=10000,q,sum=0,s=0;
	scanf("%d%d",&n,&k);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&q);
		a[q]++;
		if(q>max)
		max=q;
		if(q<min)
		min=q;
	}
	for(i=min;i<=min+k;i++)
	sum+=a[i];
	if(sum>s)
	s=sum;
	for(i;i<=max;i++)
	{
		sum+=a[i]-a[i-k-1];
		if(sum>s)
		s=sum;
	}
	printf("%d",s);
	return 0;
}