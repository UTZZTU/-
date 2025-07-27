#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
	char ch[100],a[100];
	int len,w;
	while(gets(ch)) 
	{
		w=0;
		len=strlen(ch);
		for(int i=0;i<len;i++)
		{
			a[len-1-i]=ch[i];
		}
		a[len]='\0';
		for(int i=0;i<len;i++)
		{
			if(ch[i]==a[i]||(ch[i]-a[i])==32||(a[i]-ch[i])==32)
			w++;
			else 
			{
				printf("No\n");
				break;
			}
		}
		if(w==len)
		printf("Yes\n");
	}
	return 0;
}
