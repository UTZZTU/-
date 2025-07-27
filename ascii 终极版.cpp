#include <stdio.h>
int main ()
{
    int x,y,z;
	char a,b,c;
	while (scanf("%c%c%c",&a,&b,&c)!=EOF)
	{
		
		x=a;
		y=b;
		z=c;
		if(x>y&&y>z)
		{
			printf("%c %c %c\n",c,b,a);
		}
		else if(x>z&&z>y)
		{
			printf("%c %c %c\n",b,c,a);
		}
		else if(y>x&&x>z)
		{
			printf("%c %c %c\n",c,a,b);
		}
		else if(y>z&&z>x)
		{
			printf("%c %c %c\n",a,c,b);
		}
		else if(z>y&&y>x)
		{
			printf("%c %c %c\n",a,b,c);
		}
		else if(z>x&&x>y)
		{
			printf("%c %c %c\n",b,a,c);
		}
		getchar();
	}
	return 0;
}
