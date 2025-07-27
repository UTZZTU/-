#include <bits/stdc++.h>
using namespace std;
int t,n,a[110],res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i==1) res=a[i];
			else res^=a[i];
		}
//		printf("%d\n",res);
		if(n==1)
		{
			if(a[1])
			{
				printf("1\n");
				printf("1 1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if(n%2==0)
		{
			printf("2\n");
			printf("1 %d\n",n);
			printf("1 %d\n",n);
		}
		else
		{
			if(res)
			{
				printf("4\n");
				printf("1 %d\n",n);
				printf("1 %d\n",n-1);
				printf("%d %d\n",n-1,n);
				printf("%d %d\n",n-1,n);
			}
			else
			{
				printf("1\n");
				printf("1 %d\n",n);
//				printf("1 %d\n",n-1);
			}
		}
	}
	return 0;
}