#include<stdio.h>
#include <string.h>
int main ()
{
	char s[30],w;
	int i,l,sum,q=1;
	scanf("%s",s);
	l=strlen(s);
	sum=0;
	for(i=0;i<l-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum+=(s[i]-'0')*q;
			q++;
		}
	}
	sum%=11;
	if(sum==10)
		w='X';
	else
	w=sum+'0';
	if(s[i]==w)
	printf("Right");
	else
	{
		for(i=0;i<l-1;i++)
		printf("%c",s[i]);
		printf("%c",w);
	}
	return 0;
 } 
