#include <bits/stdc++.h>
using namespace std;
int t,n,a[110],k;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		k=1;
		for(int i=2;i<=n&&a[i]==a[i-1];i++)
		{
			k=i;
		}
		if(k==n)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d %d\n",k,n-k);
			for(int i=1;i<=n;i++)
			{
				printf("%d ",a[i]);
				if(i==k) printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}