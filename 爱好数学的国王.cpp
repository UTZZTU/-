#include <stdio.h>
#include <math.h>
int fun(int n)
{
	int tmp=sqrt(n);
	for(int i=2;i<=tmp;i++)
	if(n%i==0||n%(i+2)==0)
	return 0;
	return 1;
}
int main ()
{
    int n,t,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%d",&n);
    	for(j=n;j>=2;j--)
    	{
    		if(n%j==0)
    		{
    			if(fun(j))
    			{
    				break;
				}
			}
		}
		if(j==1)
		printf("0");
		else
		printf("%d",n/j);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
