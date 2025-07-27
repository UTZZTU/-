#include <bits/stdc++.h>
using namespace std;
int n,l,r,a[200010];
int main ()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=l&&a[i]<=r)
		{
			printf("%d ",a[i]);
		}
		else
		{
			if(a[i]<l)
			{
				printf("%d ",l);
			}
			else
			{
				printf("%d ",r);
			}
		}
	}
	return 0;
}