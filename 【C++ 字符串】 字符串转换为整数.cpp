#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main ()
{
	char s[10010];
	scanf("%s",s);
	int l,i,jw=0;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			printf("error");
			return 0;
		}
	}
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