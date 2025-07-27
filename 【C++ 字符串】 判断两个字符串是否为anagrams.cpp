#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main ()
{
	string x,y;
	int a[26],b[26],i;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	getline(cin,x);
	getline(cin,y);
	for(i=0;x[i]!='\0';i++)
	{
		a[x[i]-'a']++;
	}
	for(i=0;y[i]!='\0';i++)
	{
		b[y[i]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		if(a[i]!=b[i])
		{
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}