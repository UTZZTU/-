#include <stdio.h>
#include <string.h>
int main ()
{
	int w[20][20];
	int n,i,j,p;
	while(scanf("%d",&n)!=EOF)
	{
		memset(w,0,sizeof(w));
		w[0][0]=1;
		j=0;
		i=0;
		p=2;
		while(p<=n*n)
		{
			i++;
			while(i<n&&w[i][j]==0)
		{
			w[i][j]=p;
			p++;
			i++;
		}
		i--;
		j++;
		while(j<n&&w[i][j]==0)
		{
			w[i][j]=p;
			p++;
			j++;
		}
		j--;
		i--;
		while(i>=0&&w[i][j]==0)
		{
			w[i][j]=p;
			p++;
			i--;
		}
		i++;
		j--;
		while(j>0&&w[i][j]==0)
		{
			w[i][j]=p;
			p++;
			j--;
		}
		j++;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				printf("%d ",w[i][j]);
			}
			printf("%d",w[i][j]);
			printf("\n");
		}
	}
	return 0;
}
