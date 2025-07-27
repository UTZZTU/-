#include <stdio.h>
int str_len(char *s)
{
	int i,sum=0;
	for(i=0;s[i]!='\0';i++)
	{
		sum++;
	}
	return sum;
}
int main ()
{
	char *s,w[100000];
	gets(w);
	s=w;
	printf("%d",str_len(s));
	return 0;
}
