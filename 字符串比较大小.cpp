#include <stdio.h>
#include <string.h>
int main ()
{
	char s[105],t[105];
	scanf("%s",s);
	scanf("%s",t);
	if(strcmp(s,t)>0)
	printf("s>t");
	else if(strcmp(s,t)==0)
	printf("s=t");
	else
	printf("s<t");
	return 0;
}