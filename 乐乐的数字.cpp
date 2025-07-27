#include <stdio.h>
int main ()
{
	int a[200010],n,i,x,j,b[200010];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("0 ");
	b[0]=0;
	for(i=1;i<n;i++)
	{
		x=0;
		for(j=i-1;j>=0;j--)
		{
			if(a[j]<a[i])
			{
				x=a[j];
				break;
			}
			else
			{
				if(b[j]<a[i])
				{
					x=b[j];
					break;
				}
			}
		}
		b[i]=x;
		printf("%d",x);
		if(i!=n-1)
		printf(" ");
	}
	return 0;
}
