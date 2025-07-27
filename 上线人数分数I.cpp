#include <stdio.h>
int main ()
{
	int n,m,k,i,j,sum,x,js=0;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<=m;j++)
	    {
	    	scanf("%d",&x);
	    	sum+=x;
		}
		if(sum>=k)
		js++;
	}
	printf("%d",js);
	return 0;
}
