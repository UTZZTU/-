#include <stdio.h>
int main ()
{
	char w[300],s;
	int i=0;
	while(~scanf("%c",&s))
	{
		if(s=='.')
		break;
		else
		{
			if(s>='a'&&s<='z')
			{
				w[i]=s-'a'+1;
				i++;
			}
			else if(s==' ')
			{
				w[i]='#';
				i++;
			}	
		}
	}
	w[i]='\0';
	for(i=0;w[i]!='\0';i++)
	{
		if(w[i]=='#')
		printf("%c",w[i]);
		else
		printf("%d",w[i]);
	}
	return 0;
}