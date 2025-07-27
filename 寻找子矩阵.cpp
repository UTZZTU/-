#include <stdio.h>
int a[1000][1000];
int main ()
{
	int n,m,p,q,i,j,sum1,sum2,w,s,max=-999999999,pd;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<=n-p;i++)
	{
		for(j=0;j<=m-q;j++)
		{
			sum1=0;
			sum2=0;
			for(s=1;s<=q;s++)
			{
				if(s%2==1)
				{
					for(w=1;w<=p;w++)
					{
						sum1+=a[w+i-1][j+s-1];
					}
				}
				else
				{
					for(w=1;w<=p;w++)
					{
						sum2+=a[w+i-1][j+s-1];
					}
				}
			}
			if(sum1-sum2>sum2-sum1)
			pd=sum1-sum2;
			else
			pd=sum2-sum1;
			if(pd>max)
			max=pd;
		}
	}
	printf("%d",max);
	return 0;
}
