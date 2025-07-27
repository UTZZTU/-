#include <stdio.h>
int main ()
{
	int t,m;
	char ch[100],a[100],s;
	scanf("%d",&t);
	s=getchar();
	for(int i=1;i<=t;i++)
	{
		m=0;
		gets(ch);
		for(int w=0;ch[w]!='\0';w++)
		{
			if(ch[w]>='A'&&ch[w]<='Z'||ch[w]>='a'&&ch[w]<='z')
			{
				a[m]=ch[w];
				m++;
			}
		}
		a[m]='\0';
		printf("%s",a);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
