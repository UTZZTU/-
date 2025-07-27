#include<stdio.h>
#include <string.h>
int main ()
{
	char s[55];
	int i,cd2=1,l,ws=0,er=0;
	double cd1=1,p;
	scanf("%s",s);
	l=strlen(s);
	if(s[0]=='-')
	{
		cd1=1.5;
	}
	if(s[l-1]=='0'||s[l-1]=='2'||s[l-1]=='4'||s[l-1]=='6'||s[l-1]=='8')
	cd2=2;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		ws++;
		if(s[i]=='2')
		er++;
	}
	p=er*1.0/ws*cd1*cd2*100;
	printf("%.2f%%",p);
	return 0;
}