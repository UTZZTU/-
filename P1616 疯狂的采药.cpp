#include<stdio.h>
#include <iostream>
using namespace std;
long long int c[3000010];
int main ()
{
	long long int t,m,a[100100],b[100100],i,w;
	scanf("%lld%lld",&t,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
	}
	for(i=1;i<=m;++i)
	{
		for(w=a[i];w<=t;w++)
		{
			c[w]=max(c[w],c[w-a[i]]+b[i]);
		}
	}
	printf("%lld",c[t]);
	return 0;
 } 
