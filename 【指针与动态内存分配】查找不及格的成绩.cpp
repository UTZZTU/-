#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int n,*p=NULL,i;
	while(scanf("%d",&n)!=EOF)
	{
		p=(int*)calloc(n,sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d",p);
			if(*p<60)
			printf("%d ",*p);
			p++;
		}
		printf("\n");
	}
	return 0;
}
