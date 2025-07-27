#include <bits/stdc++.h>
using namespace std;
int n,k;
int main ()
{
	scanf("%d%d",&n,&k);
	if(k==0)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=k-1;i++)
	{
		printf("%d ",i+1);
	}
	if(k==n)
	printf("%d",1);
	else
	{
		printf("%d ",1);
		for(int i=k+1;i<=n;i++)
		{
			printf("%d",i);
			if(i!=n) printf(" ");
		}
	}
	return 0;
}