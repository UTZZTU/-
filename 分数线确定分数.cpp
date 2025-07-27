#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[10000000];
int main ()
{
	int n,k,i,sum=0,fsx;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=n-1;i>=0;i--)
	{
		sum++;
		while(a[i]==a[i-1]&&i>=1)
		{
			sum++;
			i--;
		}
		fsx=a[i];
		if(sum>=k)
		break;
		
	}
	printf("%d %d",fsx,sum);
	return 0;
}
