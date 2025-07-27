#include <stdio.h>
int main ()
{
	char s[1000];
	int i;
	while(scanf("%s",s)!=NULL)
	{
		for(i=0;s[i]!='\0';i++)
		{
			s[i]-=7;
		}
		printf("%s\n",s);
	}
	return 0;
}
