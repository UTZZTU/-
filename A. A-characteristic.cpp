#include <bits/stdc++.h>
using namespace std;
int n,k,t;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int i=0;
		for(i;i<=n;i++)
		{
			if(i*(i-1)/2+(n-i)*(n-i-1)/2==k)
			{
				break;
			}
		}
		if(i==n+1) puts("NO");
		else
		{
			puts("YES");
			for(int j=1;j<=i;j++)
			{
				printf("-1 ");
			}
			for(int j=1;j<=(n-i);j++)
			{
				printf("1 ");
			}
			printf("\n");
		}
	}
	return 0;
}