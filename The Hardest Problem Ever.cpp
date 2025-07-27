#include <stdio.h>
#include <cstring>
int main ()
{
	char str1[999];
	char str2[20];
	while(scanf("%s%*c",&str2)!=EOF)
	{
		if(strcmp(str2,"ENDOFINPUT")==0)
		break;
		else
		{
			if(strcmp(str2,"START")==0)
			{
				gets(str1);
				for(int i=0;i<999;i++)
				{
					if(str1[i]>='A'&&str1[i]<='Z')
					{
						if(str1[i]=='A')
						str1[i]='V';
						else if(str1[i]=='B')
						str1[i]='W';
						else  if(str1[i]=='C')
						str1[i]='X';
						else if(str1[i]=='D')
						str1[i]='Y';
						else if(str1[i]=='E')
						str1[i]='Z';
						else
						str1[i]=str1[i]-5;
					}
				}
				puts(str1);
			}
		}
	}
	return 0;
}
