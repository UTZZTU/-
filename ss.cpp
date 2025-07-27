#include <stdio.h>
#include <string.h>
int fun(char s[])
{
	int l,i;
	l=strlen(s);
	for(i=0;i<l/2;i++)
	{
		if(s[i]!=s[i+l/2])
		return 0;
	}
	return 1;
}
int main ()
{
	char s[205];
	int l,i,m;
	scanf("%s",s);
	l=strlen(s);
	for(i=l-2;i>=0;i-=2)
	{
		s[i]='\0';
	    if(fun(s))
	    {
	    	l=strlen(s);
	    	printf("%d",l);
	    	break;
		}
	}
	return 0;
}
