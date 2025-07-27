#include <stdio.h>
int main ()
{
	char s;
	int sum=0;
	while(scanf("%c",&s)!=EOF)
	{
		if(s=='#')
		break;
		else
		{
			if(s=='b'||s=='B'||s=='m'||s=='M')
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
