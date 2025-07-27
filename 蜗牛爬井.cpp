#include <stdio.h>
int main ()
{
	int h,a,b,t=0,day;
	scanf("%d %d %d",&h,&a,&b);
	while(1)
	{
		day++;
		t+=a;
		if(t>=h)
		{
			printf("%d",day);
			break;
		}
		t-=b;
		
	}
	return 0;
}
