#include <bits/stdc++.h>
using namespace std;
int t,n,m,a[200010],b[200010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&b[j]);
		}
		sort(b+1,b+1+m);
		int i=1,j=m;
		while(i<=n&&j>=1)
		{
			if(a[i]>b[j])
			{
				printf("%d ",a[i]);
				i++;
			}
			else
			{
				printf("%d ",b[j]);
				j--;
			}
		}
		if(i<=n)
		{
			for(i;i<=n;i++) printf("%d ",a[i]);
		}
		else
		{
			for(j;j>=1;j--) printf("%d ",b[j]);
		}
		printf("\n");
	}
	return 0;
}