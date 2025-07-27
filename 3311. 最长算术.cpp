#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main ()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n,ans=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			b[j]=a[j]-a[j-1];
		}
		for(int j=2;j<=n;j++)
		{
			int k=j;
			while(b[k]==b[k+1]) k++;
			if(k-j+2>ans)
			ans=k-j+2;
			j=k;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}