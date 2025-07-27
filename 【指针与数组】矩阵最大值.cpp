#include <stdio.h>
int fun(int w[][10],int m,int n)
{
	int 
}
int main ()
{
	int t,i,m,n,j,q,w[10][10];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&m,&n);
		for(j=0;j<m;j++)
		{
			for(q=0;q<n;q++)
			{
				scanf("%d",&w[j][q]);
			}
		}
		printf("%d",fun(w,m,n));
		if(i!=t)
		printf("\n");
	}
	return 0;
}
