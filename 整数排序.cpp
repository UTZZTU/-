#include <stdio.h>
#include <string.h>
int main ()
{
	int c[10],s[10],m;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&c[i]);
	}
	memcpy(s,c,sizeof(int)*10);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9-i;j++)
		{
			if(s[j]>s[j+1])
			{
				m=s[j];
				s[j]=s[j+1];
				s[j+1]=m;
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		printf("%d ",s[i]);
	}
	printf("%d",s[9]);
	printf("\n");
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(s[i]==c[j])
			{
				printf("%d",j+1);
				break;
			}
		}
		if(i!=9)
		printf(" ");
	}
	return 0;
}
 
