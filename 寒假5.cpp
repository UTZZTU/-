#include <stdio.h>
int main ()
{
	int n,q,i,a[1000],wt,j,b[1000];
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=1;i<=q;i++)
	{
		wt=b[i];
		j=1;
		while(wt>a[j]-1)
		{
			wt-=a[j];
			j++;
		}
		printf("%d",j);
		if(i!=q)
		printf("\n");
	}
	return 0;
}
