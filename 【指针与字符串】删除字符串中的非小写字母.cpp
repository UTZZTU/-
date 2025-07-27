#include <stdio.h>
int main ()
{
	int t,i,j,n;
	char s[110],*p,w[110];
	p=s;
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		n=0;
		gets(s);
		for(j=0;p[j]!='\0';j++)
		{
			if(p[j]>='a'&&p[j]<='z')
			{
				w[n]=p[j];
				n++;
			}
		}
		w[n]='\0';
		printf("%s",w);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
