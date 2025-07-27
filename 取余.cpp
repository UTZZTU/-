#include <stdio.h>
int main ()
{
	int n,k,sum=1;
    scanf("%d",&n);
    while(n--)
    {
    	scanf("%d",&k);
    	sum*=k;
    	sum%=10007;
	}
	printf("%d",sum);
	return 0;
}