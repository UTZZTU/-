#include <stdio.h>
#include <string.h>
int main ()
{
	char s1[205],s2[205];
	int i,bw,l1,l2,j;
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	bw=0;
	for(i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--)
	{
		s1[i]=s1[i]-s2[j]-bw+'0';
		if(s1[i]-'0'>=0)
		{
			bw=0;
		}
		else
		{
			bw=1;
			s1[i]+=10;
		}
	}
	for(i;i>=0;i--)
	{
		s1[i]=s1[i]-bw;
		if(s1[i]-'0'>=0)
		{
			bw=0;
		}
		else
		{
			bw=1;
			s1[i]+=10;
		}
	}
	for(i=0;i<l1-1&&s1[i]=='0';i++)
	;
	for(i;i<=l1-1;i++)
	printf("%c",s1[i]);
	return 0;
}
