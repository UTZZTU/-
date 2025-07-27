#include <stdio.h>
#include <string.h>
#include<iostream>
#include<string>
using namespace std;
int main ()
{
	int n,i,l,pd,q,j,sum=0,qs;
	char s[100],x;
	string w;
	scanf("%d",&n);
	getchar();
	scanf("%s",s);
	getchar();
	l=strlen(s);
	q=n;
	while(q--)
	{
		getline(cin,w);
		for(i=0;w[i]!='\0';i++)
		{
			pd=0;
			qs=0;
			while(w[i]==s[qs]&&qs<l)
			{
				pd++;
				j++;
				qs++;
			}
			if(pd==l)
			sum++;
			printf("%d\n",pd);
		}
	}
	printf("%d",sum);
	return 0;
}
