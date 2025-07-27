#include <stdio.h>
#include <string.h>
int main ()
{
	int k,m,l,i,n;
	char s[100],w[100];
	while(scanf("%d%d",&k,&m)!=EOF)
	{
		n=0;
		getchar();
		gets(s);
		l=strlen(s);
		if(k+m>l)
		m=l-k;
		for(i=0;s[i]!='\0';i++)
		{
			if(i<=k-1||i>k+m-1)
			{
				w[n]=s[i];
				n++;
			}
		}
		w[n]='\0';
		printf("%s\n",w);
	}
	return 0;
}
