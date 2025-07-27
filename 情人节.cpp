#include <stdio.h>
int main ()
{
	char s[1000][15];
	int i=1;
	while(scanf("%s",s[i])!=NULL)
	{
		if(s[i][0]=='.')
		break;
		else
		{
			i++;
		}
	}
	if(i>=15)
	printf("%s and %s are inviting you to dinner...",s[2],s[14]);
	else if(i<15&&i>=3)
	printf("%s is the only one for you...",s[2]);
	else
	printf("Momo... No one is for you ...");
	return 0;
}