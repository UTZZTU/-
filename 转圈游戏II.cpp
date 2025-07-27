#include <stdio.h>
int main ()
{
	int n,q,a,b,i,w[100000],sum=0;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	{
		w[i]=i;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==1)
		{
			sum+=b;
		}
		else
		sum-=b;
	}
	sum%=n;
	for(i=0;i<n;i++)
	{
		w[i]+=sum;
		if(w[i]<0)
		w[i]+=n;
		if(w[i]>=n)
		w[i]%=n;
	}
	for(i=0;i<n-1;i++)
	printf("%d\n",w[i]);
	printf("%d",w[i]);
	return 0;
}
