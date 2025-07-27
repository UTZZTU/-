#include <stdio.h>
#include <string.h>
int main ()
{
	int a[100010],n,k,i,m,j,q,pd1=0,pd2=0,b[10010];
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&q);
			if(a[q]==0)
			a[q]=k;
			else
			{
				if(k>a[q])
				a[q]=k;
			}
		}
	}
	scanf("%d",&m);
	q=0;
	for(i=1;i<=m;i++)
	{
		pd1=0;
		scanf("%d",&k);
		if(q==0)
		{
			if(a[k]<=1)
			{
			b[q]=k;
			q++;
			}	
		}
		else
		{
			for(j=0;j<q;j++)
			{
				if(b[j]==k)
				{
					pd1=1;
					break;
				}
			}
			if(pd1==0)
			{
				if(a[k]<=1)
				{
					b[q]=k;
				q++;
				}
			}
		}
	}
	if(q==0)
	printf("No one is handsome");
	else
	{
		for(i=0;i<q-1;i++)
		printf("%05d ",b[i]);
		printf("%05d",b[i]);
	}
	return 0;
}