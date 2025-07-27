#include <stdio.h>
int main ()
{
	int n,w,max=1000,min=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w);
		if(w>min)
		min=w;
		if(w<max)
		max=w;
	}
	printf("%d",min-max);
	return 0;
}
