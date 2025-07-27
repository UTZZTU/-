#include <stdio.h>
#include <string.h>
int main ()
{
	char s[105];
	int l;
	scanf("%s",s);
	l=strlen(s);
	printf("%c%d%c",s[0],l-2,s[l-1]);
	return 0;
}