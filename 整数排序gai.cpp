#include <stdio.h>
int main ()
{
	int c[10],w[10000],i,j,t;
	for(i=0;i<10;i++)
	{
		scanf("%d",&c[i]);
		w[c[i]]=i+1;
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(c[j]>c[j+1])
			{
				t=c[j];
				c[j]=c[j+1];
				c[j+1]=t;
			}
		}
	}
	printf("%d",c[0]);
	for(i=1;i<10;i++)
	{
		printf(" %d",c[i]);
	}
	printf("\n");
	printf("%d",w[c[0]]);
	for(i=1;i<10;i++)
	{
		printf(" %d",w[c[i]]);
	}
	return 0;
}
