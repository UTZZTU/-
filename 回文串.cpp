#include <stdio.h>
#include <string.h>
int main ()
{
	char s[105];
	int i,l;
	scanf("%s",s);
	l=strlen(s);
	l--;
	for(i=0,l;s[i]==s[l];i++,l--)
	;
	if(i>=l)
	printf("YES");
	else
	printf("NO");
	return 0;
}