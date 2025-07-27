#include <stdio.h>
#include <string.h>
int main ()
{
	char s[100010];
	scanf("%s",s);
	int i,a[26],pd=0;
	memset(a,0,sizeof(a));
	for(i=0;s[i]!='\0';i++)
	{
		a[s[i]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		if(a[i]==0)
		{
			pd=1;
			printf("%c",i+'a');
			break;
		}
	}
	if(pd==0)
	printf("None");
	return 0;
}