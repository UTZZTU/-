#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main ()
{
	int a,b;
	char s[20];
	scanf("%s",s);
	scanf("%d %d",&a,&b);
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>'5'&&s[i]<'9')
		{
			if(a>='9'-s[i])
			{
				a-='9'-s[i];
				s[i]='9';
			}
			else if(b>=s[i]-'0'+1)
			{
			      b-=s[i]-'0'+1;
			      s[i]='9';
			}
			else
			{
				s[i]+=a;
				a=0;
			}
		}
		else if(s[i]<='5'&&s[i]>'0')
		{
			
			if(b>=s[i]-'0'+1)
			{
			      b-=s[i]-'0'+1;
			      s[i]='9';
			}
			else if(a>='9'-s[i])
			{
				a-='9'-s[i];
				s[i]='9';
			}
			else
			{
				s[i]+=a;
				a=0;
			}
		}
	}
	printf("%s",s);
	return 0;
}