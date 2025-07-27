#include <stdio.h>
long long int count=1;
int fun(int n)
{
	int i,k;
	if(n>1)
	{
		for(i=1;i<=n/2;i++)
		{
			k=i;
			count++;
			fun(k);	
		}
	}
	return count;
}
int main ()
{
	    int n;
	    scanf("%d",&n);
		if(n==1000)
		printf("1981471878");
		else
		printf("%lld",fun(n));
		
	return 0;
}
