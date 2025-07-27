#include <stdio.h>
#include <string.h>
int main ()
{
	char s[32];
	int n,sum,i,t;
	while(gets(s)!=NULL)
	{
		t=1;
		sum=0;
		n=strlen(s);
		for(i=n-1;i>=0;i--)
		{
			sum+=(s[i]-'0')*t;
			t*=2;
		}
		printf("%u\n",sum);
	}
	return 0;
}
