#include <bits/stdc++.h>
using namespace std;
int t,n,a[110],flag;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int k=1;;k++)
		{
			int i=pow(2,k)+1,j=pow(2,k+1);
			j=min(j,n);
			if(i>=n) break;
			for(int u=i+1;u<=j;u++)
			{
				if(a[u]<a[u-1])
				{
					flag=0;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}