#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],sum;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			int j=i;
			while(j<=n&&a[j+1]==a[i])
			j++;
			if((i==1||a[i]<a[i-1])&&(j>=n||a[j]<a[j+1]))
			sum++;
			i=j;
			if(sum>=2)
			break;
		}
		if(sum==1)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}