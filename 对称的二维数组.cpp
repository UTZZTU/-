#include <stdio.h>
int main ()
{
	int n,w,s;
	while(scanf("%d",&n)!=EOF)
	{
		w=0;
		if(n==0)
		break;
		else
		{
			int a[10][10],b[10][10];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					scanf("%d",&a[i][j]);
					b[j][i]=a[i][j];
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(a[i][j]==b[i][j])
					w++;
					else break;
				}
			}
			if(w==n*n)
			printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
