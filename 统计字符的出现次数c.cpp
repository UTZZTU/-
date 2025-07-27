#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	char s[200];
	while(gets(s)!=NULL)
	{
		int l=strlen(s),sum=0,i;
		for(i=1;i<l;i++)
		{
			if(s[i]==s[0]||s[i]>='a'&&s[i]<='z'&&s[i]-s[0]==32||s[0]>='a'&&s[0]<='z'&&s[0]-s[i]==32)
			{
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}