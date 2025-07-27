#include <stdio.h>
#include <string.h>
int main ()
{
	int k,i=0;
	char s[100];
	scanf("%d",&k);
	getchar();
	while(~scanf("%s",s))
	{
		i++;
		if(strcmp(s,"End")==0)
		break;
		else
		{
			if(i==k+1)
			{
				printf("%s\n",s);
				i=0;
			}
			else
			{
				if(strcmp(s,"ChuiZi")==0)
				printf("Bu\n");
				else if(strcmp(s,"JianDao")==0)
				printf("ChuiZi\n");
				else
				printf("JianDao\n");
			}
		}
	}
	return 0;
}