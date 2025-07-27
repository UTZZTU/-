#include <stdio.h>
int main ()
{
	int d,n,i,k,a[55],sum=0,s=0;
	scanf("%d%d",&d,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	sum+=d/s*n;
	d%=s;
	if(d==0)
	printf("%d",sum);
	else
	{
		for(i=1;i<=n;i++)
	{
		d-=a[i];
		sum++;
		if(d<=0)
		break;
	}
	printf("%d",sum);
	}
	return 0;
}