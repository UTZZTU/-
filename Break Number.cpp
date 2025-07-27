#include <stdio.h>
#include <string.h>
int main ()
{
	int n,a[101],max=0,i,k;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=i;
		while(k%2==0)
		{
			k/=2;
			a[i]++;
		}
		if(a[i]>max)
		max=a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==max)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}