#include <iostream>
#include <string.h>
#include <string.h>
using namespace std;
int main ()
{
	int n,i,j,l;
	char a[10010];
	cin>>n;
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a);
		l=strlen(a);
		a[l-1]='\0';
		for(j=0;a[j]!='\0';j++)
		{
			if(a[j]==' ')
			a[j]='@';
		}
		printf("%s\n",a);
	}
	return 0;
}