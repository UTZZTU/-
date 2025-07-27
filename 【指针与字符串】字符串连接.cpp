#include <stdio.h>
void fun(char *p1,char *p2,char *p3)
{
	int i,j;
	for(i=0;p1[i]!='\0';i++)
	{
		p3[i]=p1[i];
	}
	for(j=0;p2[j]!='\0';j++)
	{
		p3[i+j]=p2[j];
	}
	p3[i+j]='\0';
}
int main ()
{
	int t,i;
	char s1[100],s2[100],s3[100],*p1,*p2,*p3;
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{
		gets(s1);
		gets(s2);
		p1=s1;
		p2=s2;
		p3=s3;
		fun(p1,p2,p3);
		printf("%s",s3);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
