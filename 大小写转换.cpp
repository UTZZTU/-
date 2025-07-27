#include <stdio.h>
int main ()
{
	int t,i,j;
	char s[200];
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		gets(s);
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]>='a'&&s[j]<='z')
			s[j]-=32; 
		}
		printf("%s\n",s);
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]>='A'&&s[j]<='Z')
			{
				s[j]+=32;
			}
		}
		printf("%s",s);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
