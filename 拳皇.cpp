#include <stdio.h>
int main ()
{
	int xl1,xl2,gj1,gj2,i;
	scanf("%d%d%d%d",&xl1,&gj1,&xl2,&gj2);
	for(i=1;;i++)
	{
		xl2-=gj1;
		if(xl2<=0)
		{
			printf("Left");
			break;
		}
		xl1-=gj2;
		if(xl1<=0)
		{
			printf("Right");
			break;
		}
	}
	return 0;
}