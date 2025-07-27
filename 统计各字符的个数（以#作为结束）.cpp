#include <stdio.h>
int main ()
{
	char s;
	int a1=0,a2=0,a3=0,a4=0;
	while(scanf("%c",&s)!=EOF)
	{
		if(s=='#')
		break;
		else
		{
			if(s>='A'&&s<='Z')
			a1++;
			else if(s>='a'&&s<='z')
			a2++;
			else if(s>='0'&&s<='9')
			a3++;
			else
			a4++;
		}
	}
	printf("%d %d %d %d",a1,a2,a3,a4);
	return 0;
}
