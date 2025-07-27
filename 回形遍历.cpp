#include <stdio.h>
int main ()
{
	int c[9][9],w[9][9];
	int t,i,j,n,a,sum;
	scanf("%d",&t);
	for(a=1;a<=t;a++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&c[i][j]);
				w[i][j]=0;
			}
		}
		i=0,j=0;
		sum=1;
		w[0][0]=c[0][0];
		printf("%d",c[0][0]);
		while(sum<n*n)
		{
			j+=1;
			while(j<n&&w[i][j]==0)
		{
			w[i][j]=c[i][j];
			printf(" %d",c[i][j]);
			sum++;
			j++;
		}
		j--;
		i++;
		    while(i<n&&w[i][j]==0)
		    {
		    	w[i][j]=c[i][j];
		    	printf(" %d",c[i][j]);
		    	sum++;
		    	i++;
			}
			i--;
			j--;
			while(j>=0&&w[i][j]==0)
			{
				w[i][j]=c[i][j];
				printf(" %d",c[i][j]);
				sum++;
				j--;
			}
			j++;
			i--;
			while(i>=0&&w[i][j]==0)
			{
				w[i][j]=c[i][j];
				printf(" %d",c[i][j]);
				sum++;
				i--;
			}
			i++;
		}
		if(a!=t)
		{
			printf("\n");
		}
	}
	return 0;
}
