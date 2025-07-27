#include <stdio.h>
#include <string.h>
int main ()
{
	char s[10][100];
	int n,i,len,max=0,q;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(s[i]);
		len=strlen(s[i]);
		if(len>max)
		{
			max=len;
			q=i;
		}
	}
	printf("%s",s[q]);
	return 0;
}
