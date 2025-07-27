#include <stdio.h>
void fun(int *p,int t)
{
	*p=*p*10+t;
}
int main ()
{
	int a,n,i,*p,t;
	p=&a;
	while(scanf("%d%d",&a,&n)!=EOF)
	{
		int sum;
		sum=0;
		t=a;
		for(i=1;i<=n;i++)
		{
			sum+=a;
			fun(p,t);
		}
		printf("%d\n",sum);
	}
	return 0;
}
