#include <stdio.h>
#include <string.h>
int main ()
{
	char s[100010],w[100010];
	int i,q=0,l;
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i+=2)
	{
		w[q]=s[i];
		q++;
	}
	w[q]='\0';
	printf("%s",w);
	return 0;
}