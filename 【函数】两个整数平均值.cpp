#include <stdio.h>
char c[100];
 int fun()
{
	gets(c);
	int w=0;
	for(int i=0;c[i]!='\0';i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		w++;
	}
	printf("%d",w);
}
int main ()
{
	int n;
	char s;
	scanf("%d",&n);
	s=getchar();
	for(int i=1;i<=n;i++)
	{
		fun();
		if(i!=n)
		printf("\n");
	}
	
	return 0;
}
