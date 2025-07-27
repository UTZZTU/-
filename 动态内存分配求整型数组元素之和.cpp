#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int a,*p=NULL,n,i,sum=0;
	scanf("%d",&n);
	p=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",p);
		sum+=*p;
		p++;
	}
	printf("%d",sum);
	return 0;
}
