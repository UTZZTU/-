#include <stdio.h>
int a[1010][1010],b[1010][1010],c[1010][1010],a1,a2,a3,a4,i,j,w,sum;
int main ()
{
	
	scanf("%d%d",&a1,&a2);
	for(i=1;i<=a1;i++)
	{
		for(j=1;j<=a2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d",&a3,&a4);
	for(i=1;i<=a3;i++)
	{
		for(j=1;j<=a4;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	if(a2!=a3)
	printf("Error: %d != %d",a2,a3);
	else
	{
		for(i=1;i<=a1;i++)
		{
			for(j=1;j<=a4;j++)
			{
				sum=0;
				for(w=1;w<=a3;w++)
				{
					sum+=a[i][w]*b[w][j];
				}
				c[i][j]=sum;
			}
		}
		printf("%d %d\n",a1,a4);
		for(i=1;i<=a1;i++)
		{
			for(j=1;j<a4;j++)
			{
				printf("%d ",c[i][j]);
			}
			printf("%d",c[i][j]);
			printf("\n");
		}
	}
	return 0;
}
