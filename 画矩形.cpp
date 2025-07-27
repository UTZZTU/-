#include <stdio.h>
int main ()
{
	int h,d,e,i,q;
	char c;
	scanf("%d %d %c %d",&h,&d,&c,&e);
	q=h-2;
	if(e==0)
	{
		for(i=1;i<=d;i++)
		{
			printf("%c",c);
		}
		printf("\n");
		while(q--)
		{
			printf("%c",c);
			for(i=1;i<=d-2;i++)
			{
				printf(" ");
			}
			printf("%c",c);
			printf("\n");
		}
		for(i=1;i<=d;i++)
		{
			printf("%c",c);
		}
	}
	else if(e==1)
	{
	while(h--)
	{
		for(i=1;i<=d;i++)
		{
			printf("%c",c);
		}
		printf("\n");
	}	
	}
	return 0;
}
