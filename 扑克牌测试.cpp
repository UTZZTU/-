#include <stdio.h>
#include <string.h>
#define n 6
int main ()
{
	char s[6][100],i;
	int l;
	for(i=0;i<n;i++)
	{
		gets(s[i]);
		l=strlen(s[i]);
		printf("%d\n",l);
	}
	return 0;
}
