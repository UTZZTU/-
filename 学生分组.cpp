#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,i,a[101],x,q,h,sum=0;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++;
		a[x]=a[x]%2;
	}
	for(i=1;i<=100;i++)
	{
		if(a[i]!=0)
		{
			q=i;
			i++;
			while(a[i]==0)
			{
				i++;
			}
			h=i;
			sum+=h-q;
		}
	}
	printf("%d",sum);
	return 0;
}
