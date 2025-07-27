#include <stdio.h>
int c(char s)
{
	if(s>='0'&&s<='9')
	{
			return 1;
	}
	else return 0;
	
}
int main ()
{
	char s;
	while(scanf("%c",&s)!=EOF)
	{
		if(s=='\n')
		continue;
		if(c(s)==1)
		printf("Digit\n");
		else if(c(s)==0)
		 printf("Other\n"); 
	}
	return 0;
}
