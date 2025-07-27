#include <stdio.h>
int main ()
{
	int n,i,j,sum,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<=5;j++)
		{
			scanf("%d",&k);
			sum+=k;
		}
		sum%=26;
		printf("%c",sum+'a');
		if(i!=n)
		printf("\n");
	}
	return 0;
}
