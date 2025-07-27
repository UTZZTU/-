#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
	int i,c[300],n;
	char s[100],w[100];
	memset(c,0,sizeof(c));
	while(gets(s)!=NULL)
	{
		n=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(c[s[i]]!=1)
			{
				c[s[i]]=1;
				w[n]=s[i];
				n++;
			}
		}
		w[n]='\0';
		printf("%s\n",w);
	}
	return 0;
}
