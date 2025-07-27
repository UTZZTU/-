#include <stdio.h>
#include <string.h>
int main ()
{
	int i,c[210],n,t,j;
	char s[210];
	while(gets(s)!=NULL)
	{
		t=0;
		for(i=0;s[i]!='\0';i++)
		{
			c[i]=s[i];
		}
		n=i;
		for(j=0;j<(n-1)/2;j+=2)
		{
			if(c[j]==c[i-2-j]&&c[j+1]==c[i-1-j])
			{
				t++;
			}
			else break;
		}
		if(t==n/4)
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}
