#include <stdio.h>
#include <string.h>
int main ()
{
	int a[10010],m,i,q,h,l,sum=0,j;
	memset(a,0,sizeof(a));
	scanf("%d%d",&l,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&q,&h);
		for(j=q;j<=h;j++)
		a[j]=1;
	}
	for(i=0;i<=l;i++)
	sum+=a[i];
	printf("%d",l+1-sum);
	return 0;
}