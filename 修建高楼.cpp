#include <stdio.h>
#include <string.h>
int main ()
{
	int t,n,i,a[2005],b[60],j,k,m,max=0,w;
	memset(b,0,sizeof(b));
	scanf("%d%d",&t,&n);
	m=0;
	w=t;
	while(w--)
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<=n-3;i++)
		{
			for(j=i+1;j<=n-2;j++)
			{
				for(k=j+1;k<=n-1;k++)
				{
					if(a[k]-a[j]==a[j]-a[i])
					{
						b[m]++;
					}
				}
			}
		}
		if(b[m]>max)
		max=b[m];
		m++;
	}
	for(i=0;i<t;i++)
	if(b[i]==max)
	printf("%d %d",i+1,b[i]);
	return 0;
}
