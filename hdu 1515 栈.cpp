#include <iostream>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
int a[1010];
char s1[1010],s2[1010];
void fun(int x)
{
	stack<char> p;
	char s[1010];
	int i,j,sum=0,pd=0,num=0;
	for(i=1;i<=x;i++)
	{
		if(a[i]==1)
		{
			if(p.empty())
			{
				pd=1;
				break;
			}
			else
			{
				s[sum]=p.top();
				p.pop();
				if(s[sum]!=s2[sum])
				{
					pd=1;
					break;
				}
				sum++;
			}
		}
		else if(a[i]==0)
		{
			if(num>=x)
			{
				pd=1;
				break;
			}
			else
			{
				p.push(s1[num]);
				num++;
			}
		}
	}
	s[sum]='\0';
	if(pd==0&&strcmp(s,s2)==0)
	{
		for(i=1;i<x;i++)
		{
			if(a[i]==1)
			printf("o");
			else
			printf("i");
			printf(" ");
		}
		    if(a[i]==1)
			printf("o");
			else
			printf("i");
			printf("\n");
	}
}
int main ()
{
	while(~scanf("%s %s",s1,s2))
	{
		memset(a,0,sizeof(a));
		int i,j,num1[26],pd=0;
		memset(num1,0,sizeof(num1));
		for(i=0;s1[i]!='\0';i++)
		{
			num1[s1[i]-'a']++;
		}
		for(i=0;s2[i]!='\0';i++)
		{
			num1[s2[i]-'a']--;
		}
		for(i=0;i<26;i++)
		{
			if(num1[i]!=0)
			{
				pd=1;
				break;
			}
		}
		if(pd==1)
		{
			printf("[\n]\n");
		}
		else
		{
			printf("[\n");
			int l=strlen(s1);
			l*=2;
			while(a[0]==0)
			{
				a[l]++;
				i=l;
				while(a[i]>=2)
				{
					a[i]=0;
					i--;
					a[i]++;
				}
				if(a[0]==1)
				break;
				fun(l);
			}
			printf("]\n");
		}
	}
	return 0;
}