#include <stdio.h>
#include <string.h>
int main ()
{
	char s[30],k,q;
	int i=0,l;
	scanf("%c",&k);
	q=k;
	while(q-'A'>=0)
	{
		s[i]=q;
		q--;
		i++;
	}
	q++;
	while(k-q>=1)
	{
		s[i]=q;
		q++;
		i++;
	}
	s[i]='\0';
	l=strlen(s);
	for(i=0;i<k-'A'+1;i++)
	{
		printf("%s\n",s);
		s[i]=s[l-i-1]=' ';
	}
	return 0;
}