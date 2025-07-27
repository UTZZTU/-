#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
	char s,w[110];
	while(s=getchar())
	{
		gets(w);
		int sum=0;
		if(s>='a'&&s<='z')
		{
			for(int i=0;w[i]!='\0';i++)
			{
				if(w[i]==s||s==w[i]+32)
				sum++;
			}
		}
		else if(s>='A'&&s<='Z')
		{
			for(int i=0;w[i]!='\0';i++)
			{
				if(w[i]==s||s==w[i]-32)
				sum++;
			}
		}
		else
		{
			for(int i=0;w[i]!='\0';i++)
			{
				if(w[i]==s)
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
