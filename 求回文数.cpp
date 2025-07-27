#include <stdio.h>
#include <string.h>
int main ()
{
	int n,j,k=0,a[10010],i,sum=0;
	memset(a,0,sizeof(a));
	for(i=1;i<=10000;i++)
	{
		k=0;
		j=i;
		while(j)
	{
		k=k*10+j%10;
		j/=10;
	}
	if(k==i)
	a[i]=1;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	printf("%d",sum);
	return 0;
}
