#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
	int n,i,a[100010],b[100010],k,sum1=0,sum2=0,js=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		k=max(a[i]-a[i-1],a[i-1]-a[i]);
		if(k>=10)
		{
			b[i]=1;
			sum1++;
		}
		else
		b[i]=0;
	}
	for(i=1;i<n;i++)
	{
		js=0;
		while(b[i]==1&&i<n)
		{
			js++;
			i++;
		}
		if(js>=2)
		sum2++;
	}
	printf("%d %d",sum1,sum2);
	return 0;
}