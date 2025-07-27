#include <stdio.h>
int main ()
{
	int t,m,a,b,k,sum,q;
	double s;
	int c[10000],w[10000];
	scanf("%d",&t);
	while(t--)
	{
		q=100000000;
	scanf("%d %d %d",&m,&a,&b);
	for(int i=0;i<=m-1;i++)
	{
		scanf("%d",&k);
		c[i]=k;
	}
	for(int i=0;i<=m-1;i++)
	{
		sum=0;
		for(int r=1;r<i+1;r++)
		{
			s=((i+1-r)*b+0.5*(i-r)*(i-r-1))*c[r-1];
			sum+=s;
		}
		for(int r=i+2;r<=m;r++)
		{
			s=((r-i-1)*a+0.5*(r-i-1)*(r-i-2))*c[r-1];
			sum+=s;
		}
		w[i]=sum;
		if(sum<q)
		q=sum;
	}
	for(int i=0;i<=m-1;i++)
	{
		if(q==w[i])
		{
			printf("%d\n",i+1);
			break;
		}
	}
}
	return 0;
}
