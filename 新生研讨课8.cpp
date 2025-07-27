#include <stdio.h>
int main ()
{
	int a,b,n,s,m=1,sum;
	double c;
	scanf("%d",&n);
	sum=n;
	b=n;
	a=n;
	while(scanf("%d",&s)!=EOF)
	{
		if(s<a)
			a=s;
			if(s>b)
			b=s;
			sum+=s;
			m++;
	}
	c=sum*1.0/m;
	printf("%d %d %.3f",a,b,c);
	return 0;
}
