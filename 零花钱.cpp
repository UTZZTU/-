#include <stdio.h>
int main ()
{
	int s,i,k;
	scanf("%d",&s);
	for(i=1;i<=5;i++)
	{
		scanf("%d",&k);
		s-=k;
	}
	printf("%d",s);
	return 0;
}