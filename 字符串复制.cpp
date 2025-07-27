#include <stdio.h>
int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n,w=0;
		char c[100],b[100],s;
		scanf("%d%d",&m,&n);
		s=getchar();
		gets(c);
		for(int i=m;i<=n;i++)
		{
			b[w]=c[i];
			w++;
		}
		b[w]='\0';
		puts(b);
	}
	return 0;
}
