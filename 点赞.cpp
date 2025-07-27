#include <stdio.h>
#include <string.h>
int main ()
{
	int i,j,n,k,a[1005],max=0,bh;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&j);
		for(i=1;i<=j;i++)
		{
		    scanf("%d",&k);
		    a[k]++;
		}
	}
	for(i=1;i<=1000;i++)
	{
		if(a[i]>=max)
		{
			max=a[i];
			bh=i;
		}
	}
	printf("%d %d",bh,max);
	return 0;
}