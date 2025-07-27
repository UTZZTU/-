#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		int a[50]={0},res;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			res=1;
			while(k)
			{
				a[res]+=k%2;
				k/=2;
				res++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int num=0;
			for(int j=1;j<=31;j++)
			{
				if(i>n-a[j])
				num+=pow(2,j-1);
			}
			printf("%d ",num);
		}
		printf("\n");
	}
	return 0;
}