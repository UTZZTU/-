#include <stdio.h>
void fun(char *p,char *m,char *n)
{
	int i,a1,a2;
	a1=0;
	a2=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>='0'&&p[i]<='9')
		{
			n[a2]=p[i];
			a2++;
		}
		else
		{
			m[a1]=p[i];
			a1++;
		}
	}
	m[a1]='\0';
	n[a2]='\0';
}
int main ()
{
	int t,i;
	char s[100],*p,w[100],q[100],*m,*n;
	p=s;
	m=w;
	n=q;
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		gets(s);
		fun(p,m,n);
		printf("%s%s",w,q);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
