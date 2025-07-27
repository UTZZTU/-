#include <stdio.h>
#include <iostream>
using namespace std;
char s1;
int main ()
{
	int a=0,b=0;
	while(s1!='E')
	{
		cin>>s1;
		if(s1=='F')
		a++;
		else if(s1=='A')
		b++;
		if(a==11&&b<10||b==11&&a<10)
		{
			printf("%d:%d\n",a,b);
			a=0;
			b=0;
		}
		if(a>=10&&b>=10)
		{
			if(a-b==2||b-a==2)
			{
				printf("%d:%d\n",a,b);
				a=0;
				b=0;
			}
		}
	}
	if(a!=0&&b!=0)
	printf("%d:%d",a,b);
	return 0;
}
