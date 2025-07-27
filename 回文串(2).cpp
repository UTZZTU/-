#include <stdio.h>
#include <string.h>
int main ()
{
	int i,c[310],n,t,j,e,k;
	char s[310];
	while(gets(s)!=NULL)
	{
		t=0;
		for(i=0;s[i]!='\0';i++)
		{
			c[i]=s[i];
		}
		n=i;
		e=n/3;
		k=1;
		for(j=0;k<=e/2;j+=3)
		{
			if(c[j]==c[i-3-j]&&c[j+1]==c[i-2-j]&&c[j+2]==c[i-1-j])
			{
				t++;
				k++;
			}
			else break;
		}
		if(t==e/2)
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}
