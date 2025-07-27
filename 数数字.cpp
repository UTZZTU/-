#include <stdio.h>
#include <string.h>
int main ()
{
	int t,a[10],n,i,k;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			k=i;
			while(k!=0)
			{
				a[k%10]++;
				k/=10;
			}
		}
		for(i=0;i<10;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}