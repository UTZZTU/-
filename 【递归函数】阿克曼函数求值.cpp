#include <stdio.h>
int fun(int m,int n)
{
	if(m==0&&n>0)
	return n+1;
	else if(m>0&&n==0)
	return fun(m-1,1);
	else
	{
		return fun(m-1,fun(m,n-1));
	}
}
int main ()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		printf("%d\n",fun(m,n));
	}
	return 0;
}
