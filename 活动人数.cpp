#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,l,k,i,sum=0,a[1010];
	scanf("%d%d%d",&n,&l,&k);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(l>=a[i])
		{
			l+=k;
			sum++;
		}
		else
		break;
	}
	printf("%d",sum);
	return 0;
}