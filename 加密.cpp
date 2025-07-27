#include <stdio.h>
int main ()
{
	char s[]="yzabcdefghijklmnopqrstuvwx",w[105];
	int i;
	scanf("%s",w);
	for(i=0;w[i]!='\0';i++)
	{
		if(w[i]>='a'&&w[i]<='z')
		w[i]=s[w[i]-'a'];
		else
		w[i]=s[w[i]-'A']-32;
	}
	printf("%s",w);
	return 0;
}