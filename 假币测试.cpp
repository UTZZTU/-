#include <stdio.h>
int main ()
{
	int j,n; 
	char z[3][40],y[3][40],h[3][40];
	scanf("%d",&n);
	getchar();
	for(j=0;j<3;j++)
		{
			scanf("%s",&z[j]);
			scanf("%s",&y[j]);
			scanf("%s",&h[j]);
		}
		for(j=0;j<3;j++)
		{
			printf("%s %s %s\n",z[j],y[j],h[j]);
		}
}
