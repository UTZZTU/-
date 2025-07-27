#include <stdio.h>
int main ()
{
	int i,j,k;
	char s[10000];
	while(gets(s)!=NULL)
	{
		k=1;
		for(i=0;s[i]!='\0';)
		{
			for(j=i+1;s[j]==s[i];j++)
			{
				k++;
			}
			if(k>1)
			printf("%d",k);
			printf("%c",s[i]);
			i=j;
			k=1;
		}
		printf("\n");
	}
	return 0;
}
