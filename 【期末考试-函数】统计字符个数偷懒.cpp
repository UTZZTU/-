#include <stdio.h>
int main ()
{
	int t,i,j,sum;
	char s[100],ch;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
			getchar();
		sum=0;
		gets(s);
		scanf("%c",&ch);
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]==ch)
			sum++;
		}
		printf("%d",sum);
		if(i!=t)
		printf("\n");
	}
	return 0;
 } 
