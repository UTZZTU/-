#include <stdio.h>
int fun(int n)
{
	int i=0;
	while(n!=0)
	{
		i++;
		n/=10;
	}
	return i;
}
int main ()
{
	int n1,n2,a[1005],i,n,j,sum,t,m;
	scanf("%d %d %d",&n1,&n2,&n);
	a[1]=n1;
	a[2]=n2;
	m=3;
	for(i=3;m<=n;i++)
	{
		sum=a[i-1]*a[i-2];
		if(sum<=9)
		{
			a[m]=sum;
			m++;
		}
		else
		{
			t=fun(sum);
			for(j=m+t-1;j>=m;j--)
			{
				a[j]=sum%10;
				sum/=10;
			}
			m+=t;
		}
	}
	for(i=1;i<n;i++)
	printf("%d ",a[i]);
	printf("%d",a[i]);
	return 0;
}