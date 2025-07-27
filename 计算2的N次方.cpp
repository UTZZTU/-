#include <stdio.h>
#include <string.h>
int main ()
{
	char s1[105];
	memset(s1,'0',sizeof(s1));
	s1[104]='1';
	int n,i,jw;
	scanf("%d",&n);
		while(n--)
	{
		jw=0;
		for(i=104;i>=0;i--)
		{
			s1[i]=(s1[i]-'0')*2+jw+'0';
			jw=(s1[i]-'0')/10;
			s1[i]=(s1[i]-'0')%10+'0';
		}
	}
	for(i=0;s1[i]=='0';i++)
	;
	for(i;i<=104;i++)
	printf("%c",s1[i]);
	return 0;
}
