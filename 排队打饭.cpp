#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int fun(int a)
{
	int i,n=1;
		for(i=2;i<=a;i++)
	{
		n*=i;
		n%=2011;
	}
	return n;
}
int main ()
{
	int n,a[109],b[101],i,sum=0,t=0,w=1;
	scanf("%d",&n);
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	sort(a,a+n);
	for(i=1;i<n;i++)
	{
		t+=a[i-1];
		sum+=t;
	}
	for(i=1;i<=100;i++)
	{
		w*=fun(b[i]);
		w%=2011;
	}
	printf("%d %d",sum,w);
	return 0;
}
