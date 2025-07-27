#include <bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
int main ()
{
	int n,m,k;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		int j=lower_bound(a+1,a+1+n,k)-a;
		if(j>n||a[j]!=k)
		b[i]=-1;
		else
		b[i]=j;
	}
	for(int i=1;i<=m;i++)
	{
		if(i!=1)
		printf(" ");
		printf("%d",b[i]);
	}
	return 0;
}