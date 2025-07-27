#include <stdio.h>
int main  ()
{
	int n,m,x,sum1=0,sum2=0,i;
	scanf("%d",&n);
	 for(i=1;i<=n;i++)
	 {
	 	scanf("%d",&x);
	 	sum1+=x;
	 }
	 scanf("%d",&m);
	 for(i=1;i<=m;i++)
{
	scanf("%d",&x);
	sum2+=x;
}
if(sum1>sum2)
{
	printf("A\n");
}
else
printf("B\n");
printf("%d %d",sum1,sum2);
return 0;
}
