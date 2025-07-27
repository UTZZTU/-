#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int w=0,e=0;
		char c;
		while(scanf("%c",&c)!=EOF)
		{
			if(c>='0'&&c<='9')
			{
				w++;
				e++;
			}
			else if(c>='a'&&c<='z')
			e++;
			if(c=='\n'&&e>=1)
			break;
		
		}
		printf("%d\n",w);
		
	}
	return 0;
}
