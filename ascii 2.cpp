#include <stdio.h>
int main ()
{
	char a,b,c;
	int x,y,z;
	scanf("%c%c%c",&a,&b,&c);
	x=a;
		y=b;
		z=c;
		if(x>y&&y>z)
		{
			printf("%c %c %c",c,b,a);
		}
		else if(x>z&&z>y)
		{
			printf("%c %c %c",b,c,a);
		}
		else if(y>x&&x>z)
		{
			printf("%c %c %c",c,a,b);
		}
		else if(y>z&&z>x)
		{
			printf("%c %c %c",a,c,b);
		}
		else if(z>y&&y>x)
		{
			printf("%c %c %c",a,b,c);
		}
		else if(z>x&&x>y)
		{
			printf("%c %c %c",b,a,c);
		}
		return 0;
	
}
