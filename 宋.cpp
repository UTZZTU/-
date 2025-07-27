#include<stdio.h>
char f(char ch)
{
	if(ch>='0'&&ch<='9')
	{
		ch='9'-ch+'0';
	}
	return ch;
}
int main()
{
	char n;
	while(scanf("%c",&n)!=EOF)
	{
		printf("%c\n",f(n));
		getchar();
	}
	return 0;
}
