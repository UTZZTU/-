#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	int k,i,a[26],b[26],sum=0,l=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	char s[110];
	cin>>k;
	getchar();
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		a[s[i]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		if(a[i])
		sum++;
	}
	if(sum<k)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
	for(i=0;s[i]!='\0'&&l<k;i++)
	{
		if(b[s[i]-'a']==0)
		{
			b[s[i]-'a']=1;
			printf("\n");
			l++;
			printf("%c",s[i]);
		}
		else
		printf("%c",s[i]);
	}
	for(i;s[i]!='\0';i++)
	{
		printf("%c",s[i]);
	}
	return 0;
}