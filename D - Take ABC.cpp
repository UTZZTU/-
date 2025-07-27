#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
char s[200010],u[200010];
int len,pos;
int main ()
{
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		u[pos++]=s[i];
		while(pos>=3&&u[pos-1]=='C'&&u[pos-2]=='B'&&u[pos-3]=='A')
		{
			pos-=3;
		}
	}
	u[pos]='\0';
	printf("%s",u);
	return 0;
}