#include <stdio.h>
#include <string.h>
int main ()
{
	char s[55];
	int l,i,jw=0;
	scanf("%s",s);
	l=strlen(s);
	s[l-1]+=1;
	for(i=l-1;i>=0;i--)
	{
		s[i]+=jw;
		jw=(s[i]-'0')/10;
		s[i]=(s[i]-'0')%10+'0';
	}
	if(jw==1)
	printf("1");
	printf("%s",s);
	return 0;
 } 
