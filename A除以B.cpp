#include <stdio.h>
int main ()
{
	int a,b;
	double s;
	scanf("%d%d",&a,&b);
	if(b==0)
	printf("%d/%d=Error",a,b);
	else
	{
		s=a*1.0/b;
		if(b<0)
		printf("%d/(%d)=%.2f",a,b,s);
		else
		printf("%d/%d=%.2f",a,b,s);
	}
	return 0;
}