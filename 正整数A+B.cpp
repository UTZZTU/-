#include <stdio.h>
#include <string.h>
int main ()
{
	char s[100000];
	int a=0,b=0,pd1=0,pd2=0,l,i;
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]==' ')
		break;
		else if(s[i]>='0'&&s[i]<='9'&&pd1==0)
		a=a*10+s[i]-'0';
		else
		pd1=1;
	}
	if(i==0)
	pd1=1;
	i++;
	for(i;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9'&&pd2==0)
		b=b*10+s[i]-'0';
		else
		{
			pd2=1;
			break;
		}
	}
	if(pd1==1||a<1||a>1000)
	{
		printf("?");
		pd1=1;
	}
	else
	printf("%d",a);
	printf(" + ");
	if(pd2==1||b<1||b>1000)
	{
		printf("?");
		pd2=1;
	}
	else
	printf("%d",b);
	printf(" = ");
	if(pd1==1||pd2==1)
	printf("?");
	else
	printf("%d",a+b);
	return 0;
}