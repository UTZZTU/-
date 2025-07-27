#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int fun(int n)
{
	if(n==2||n==3)
	return 1;
	if(n%6!=1&&n%6!=5)
	return 0;
	for(int i=5;i<=floor(sqrt(n));i+=6)
	{
		if(n%i==0||n%(i+2)==0)
		return 0;
	}
	return 1;
}
int main ()
{
	int n,l,a[105],i,sum=0,b[105],m=0,j,pd=0;
	scanf("%d%d",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i+l<=n;i++)
	{
		sum=0;
		if(a[i]!=0)
		{
			sum+=a[i];
		for(j=i+1;j<i+l;j++)
		{
			sum=sum*10+a[j];
		}
		if(sum!=1)
		{
			pd=0;
			if(fun(sum))
			{
				for(j=0;j<m;j++)
				{
					if(b[j]==sum)
					pd=1;
				}
				if(pd==0)
				{
					b[m]=sum;
				m++;
				}
			}
		}
		}
	}
	sort(b,b+m);
	for(i=0;i<=m-1;i++)
	{
		printf("%d",b[i]);
		if(i!=m-1)
		printf(",");
	}
	return 0;
}


