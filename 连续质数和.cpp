#include <stdio.h>
#include <math.h>
int fun(int p)
{
	if(p==2||p==3)
	{
		return 1;
	}
	if(p%6!=1&&p%6!=5)
	{
		return 0;
	}
	for(int i=5;i<=floor(sqrt(p));i+=6)
	{
		if(p%i==0||p%(i+2)==0)
		{
			return 0;
		}
	}
	return 1;
}
int main ()
{
	int a[10000],n,i,j,sum,m,js,q,s;
	j=0;
	for(i=2;i<100000;i++)
	{
		if(fun(i))
		{
			a[j]=i;
			j++;
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=0;
		scanf("%d",&m);
		for(j=0;;j++)
		{
			if(a[j]>m)
			{
				js=j;
				break;
			}
		}
		for(j=-1;j<js-1;j++)
		{
			s=0;
			for(q=j+1;q<js;q++)
			{
				s+=a[q];
				if(s==m)
				{
					sum++;
					break;
				}
				else if(s>m)
				break;
			}
		}
		printf("%d",sum);
		if(i!=n)
		printf("\n");
	}
	return 0;
}
