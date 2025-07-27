#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long int a[100010],b[100010],c[100010];
int main ()
{
	long long int n,i,sum,k,t,w;
	memset(c,0,sizeof(c));
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
	}
	k=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&t);
		if(a[i]!=b[i])
		{
			c[k]=t;
			k++;
		}
	}
	if(k==0)
	{
		printf("0");
	}
	else
	{
		sort(c,c+k);
	w=k;
	for(i=0;i<w;i++)
	{
		sum+=k*c[i];
		k--;
	}
	printf("%lld",sum);
	}
	return 0;
}
