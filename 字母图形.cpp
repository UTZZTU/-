#include <stdio.h>
#include <string.h>
int main ()
{
	char s[100],b[100],w;
	int i,l;
	scanf("%s",s);
	l=strlen(s);
	strcpy(b,s);
	for(i=1;i<=l;i++)
	{
		printf("%s\n",b);
		b[0]=s[l-2];
		b[1]=s[l-1];
		for(w=2;w<=l-1;w++)
		{
			b[w]=s[w-2];
		}
		strcpy(s,b);
	}
	return 0;
}