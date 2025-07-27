#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	long long int a[50000],b[50000],n,m,i,j,sum=0,pd=0;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	for(j=0;j<m;j++)
	scanf("%lld",&b[j]);
	if(n>m)
	printf("-1");
	else
	{
		sort(a,a+n);
		sort(b,b+m);
		j=0;
		for(i=0;i<n;i++)
		{
			for(j;j<m;j++)
			{
				if(b[j]>=a[i])
				{
					sum+=b[j];
					b[j]=0;
					a[i]=0;
					j++;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(a[i]!=0)
			{
				pd=1;
				break;
			}
		}
		if(pd==1)
		printf("-1");
		else
		printf("%lld",sum);
	}
	return 0;
}
