#include <bits/stdc++.h>
using namespace std;
int t,n,a[15],flag;
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
		flag=1;
		while(flag)
		{
			flag=0;
			for(int i=2;i<=n-1;i++)
			{
				if(a[i]>a[i-1]&&a[i]>a[i+1])
				{
					swap(a[i],a[i+1]);
					flag=1;
				}
			}
		}
		
		int i=2;
		for(i;i<=n;i++)
		{
			if(a[i]>a[i-1])
			{
				;
			}
			else break;
		}
		if(i==n+1) puts("YES");
		else puts("NO");
	}
	return 0;
}