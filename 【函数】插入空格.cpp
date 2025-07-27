#include <stdio.h>
void fun()
{
	char a[1000],b[1000];
	int m=0;
	gets(a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(i%3==2)
		{
			b[m]=a[i];
			m++;
			b[m]=' ';
			m++;
		}
		else
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
	scanf("%d",&t);
	s=getchar();
	while(t--)
	{
		fun();
	}
	return 0;
}
