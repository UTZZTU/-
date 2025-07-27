#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int fun(int a,int b)
{
	long long sum=1,i;
	for(i=a;i>=2;i--)
	{
		sum*=i;
		sum%=1000000007;
	}
	for(i=b;i>=2;i--)
	{
		sum*=i;
		sum%=1000000007;
	}
	return sum;
}
int c[1200][1200];
int main ()
{
	int n,i,a[100010],b[100010],sum,m=1,z=0,j;
	long long int q;
	memset(c,0,sizeof(c));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		sum=1;
		while(a[i+1]==a[i])
		{
			sum++;
			i++;
		}
		if(sum>=2)
		{
			b[m]=sum;
			for(j=1;j<m;j++)
			{
				if(b[m]>c[j][0])
				{
					c[j][0]=b[m];
				}
				c[j][b[m]]++;
			}
			m++;
		}
	}
	for(i=1;i<m;i++)
	{
		for(j=2;j<=c[i][0];j++)
		{
			q=fun(b[i],j)*c[i][j];
			q%=1000000007;
			z+=q;
			z%=1000000007;
		}
	}
	printf("%d",z);
	return 0;
}
