#include <stdio.h>
int fun(int a,int b)
{
	int c;
	if(a<b)
	{
		c=a;
		a=b;
		b=c;
	}
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main ()
{
	int n,a,b,c,sum=0,k;
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	sum+=n/a+n/b+n/c;
	k=a/fun(a,b)*b;
	sum-=n/k;
	k=a/fun(a,c)*c;
	sum-=n/k;
	k=b/fun(b,c)*c;
	sum-=n/k;
	k=k/fun(k,a)*a;
	sum+=n/k;
	printf("%d",n-sum);
	return 0;
}
