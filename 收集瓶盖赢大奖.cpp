#include <stdio.h>
int main ()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>=10||y>=20)
		printf("True\n");
		else
		printf("False\n");
	}
	return 0;
}