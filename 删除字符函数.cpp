#include <stdio.h>
void fun()
{
	char b[100],a[100];
	int m=0;
	gets(a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]!='*')
		{
			b[m]=a[i];
			m++;
		}
	}
	b[m]='\0';
	puts(b);
}
int main ()
{
	int t;
	char s;
	char a[100];
	scanf("%d",&t);
	s=getchar();
	while(t--)
	{
		fun();
	}
	return 0;
}
