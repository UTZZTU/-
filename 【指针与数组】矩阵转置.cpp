#include <stdio.h>
void fun(int c[][4],int w[][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			w[j][i]=c[i][j];
		}
	}
}
int main ()
{
	int t,i,c[4][4],w[4][4],j,q;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		for(j=0;j<4;j++)
		{
			for(q=0;q<4;q++)
			{
				scanf("%d",&c[j][q]);
			}
		}
		fun(c,w);
		for(j=0;j<3;j++)
		{
			for(q=0;q<3;q++)
			{
				printf("%d ",w[j][q]);
			}
			printf("%d",w[j][3]);
			printf("\n");
		}
		for(q=0;q<3;q++)
			{
				printf("%d ",w[3][q]);
			}
			printf("%d",w[3][3]);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
