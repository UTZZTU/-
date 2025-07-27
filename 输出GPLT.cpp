#include <stdio.h>
int main ()
{
	int a1=0,a2=0,a3=0,a4=0;
	char s[10010];
	int i;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='G'||s[i]=='g')
		a1++;
		else if(s[i]=='P'||s[i]=='p')
		a2++;
		else if(s[i]=='L'||s[i]=='l')
		a3++;
		else if(s[i]=='T'||s[i]=='t')
		a4++;
	}
	while(a1+a2+a3+a4!=0)
	{
		if(a1!=0)
		{
			printf("G");
			a1--;
		}
		if(a2!=0)
		{
			printf("P");
			a2--;
		}
		if(a3!=0)
		{
			printf("L");
			a3--;
		}
		if(a4!=0)
		{
			printf("T");
			a4--;
		}
	}
	return 0;
}