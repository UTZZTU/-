#include <stdio.h>
int main ()
{
	int n,a[10]={1,0,0,0,1,0,1,0,2,1},sum=0;
	scanf("%d",&n);
	while(n!=0)
	{
		sum+=a[n%10];
		n/=10;
	}
	printf("%d",sum);
	return 0;
}