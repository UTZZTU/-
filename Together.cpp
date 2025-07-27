#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,a[300010],i,k,m=0,js,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		a[m]=k;
		m++;
		a[m]=k-1;
		m++;
		a[m]=k+1;
		m++;
	}
	sort(a,a+m);
	for(i=0;i<m;i++)
	{
		js=1;
		while(a[i]==a[i+1])
		{
			js++;
			i++;
		}
		if(js>sum)
		sum=js;
	}
	printf("%d",sum);
	return 0;
}