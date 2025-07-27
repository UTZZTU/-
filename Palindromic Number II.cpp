#include <stdio.h>
int main ()
{
	int n,m=0,k;
	scanf("%d",&n);
	k=n;
	while(k!=0)
	{
		m=m*10+k%10;
		k/=10;
	}
	if(n==m)
	printf("Yes");
	else
	printf("No");
	return 0;
}