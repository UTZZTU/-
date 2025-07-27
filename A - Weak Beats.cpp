#include <iostream>
using namespace std;
char s[20];
int main ()
{
	scanf("%s",s+1);
	for(int i=2;i<=16;i+=2)
	{
//		printf("%c\n",s[i]);
		if(s[i]!='0')
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}