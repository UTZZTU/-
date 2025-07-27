#include <stdio.h>
#include <math.h>
int a,b,c,res,t;
int cut(int x)
{
	int sum=0;
	while(x!=1)
	{
		sum++;
		x=x+1>>1;
	}
	return sum;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		res=0;
		scanf("%d%d%d",&a,&b,&c);
		res+=cut(a);
		res+=cut(b);
		res+=cut(c);
		printf("%d\n",res);
	}
	return 0;
}