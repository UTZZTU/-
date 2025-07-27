#include <stdio.h>
int main ()
{
	int n;
	double s,i;
	char w;
	scanf("%d",&n);
	while(n--)
	{
		getchar();
		scanf("%c %lf",&w,&s);
		if(w=='F')
		i=s*1.09;
		else if(w=='M')
		i=s/1.09;
		printf("%.2f\n",i);
	}
	return 0;
}