#include <stdio.h>
int main ()
{
	char x,y;
	int q,h;
	scanf("%c%*c%c",&x,&y);
	q=x-'A'+10;
	h=y-'A'+10;
	if(q<h)
	printf("<");
	else if(q>h)
	printf(">");
	else
	printf("=");
	return 0;   
}             