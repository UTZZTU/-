#include <stdio.h>
int main ()
{
	char ch,cj,ck;
	int x,y,z;
	scanf("%c%c%c",&ch,&cj,&ck);
		x=ch+3;
		y=cj+3;
		z=ck+3;
		if(x>y>z)
		{
			printf("%c %c %c",ck,cj,ch);
		}
		else if(x>z>y)
		{
			printf("%c %c %c",cj,ck,ch);
		}
		else if(y>x>z)
		{
			printf("%c %c %c",ck,ch,cj);
		}
		else if(y>z>x)
		{
			printf("%c %c %c",ch,ck,cj);
		}
		else if(z>y>x)
		{
			printf("%c %c %c",ch,cj,ck);
		}
		else if(z>x>y)
		{
			printf("%c %c %c",cj,ch,ck);
		}
	return 0;
}
