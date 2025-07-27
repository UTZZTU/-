#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void fun(char s[],int w[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		w[s[i]]++;
	}
}
int main ()
{
	int t,i,w[150],j;
	char s[210];
	scanf("%d",&t);
	getchar();
    for(i=1;i<=t;i++)
	{
		memset(w,0,sizeof(w));
		gets(s);
		fun(s,w);
		for(j=0;j<25;j++)
		{
			printf("%d ",w[65+j]+w[97+j]);
		}
		printf("%d",w[90]+w[122]);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
