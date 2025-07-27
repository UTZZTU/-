#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void fun(char *p,char *q)
{
	int i;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>='a'&&p[i]<='z')
		{
			q[i]=p[i]-32;
		}
		else if(p[i]>='A'&&p[i]<='Z')
		{
			q[i]=p[i]+32;
		}
		else
		q[i]=p[i];
	}
	q[i]='\0';
}
int main ()
{
   char email[100],s1[10000][100],s2[10000][100],a1[100],a2[100],a3[100],*p,t[100],*q;
   int n,i,j=0;
   p=a2;
   q=t;
   scanf("%s",email);
   scanf("%d",&n);
   getchar();
   for(i=0;i<n;i++)
   {
   	scanf("%s %s %s",a1,a2,a3);
   	if(strcmp(a3,email)==0)
   	{
   		strcpy(s1[j],a1);
   		fun(p,q);
   		strcpy(s2[j],t);
   		j++;
	   }
   }
   if(j==0)
   printf("empty");
   else
   {
   	for(i=0;i<j-1;i++)
   {
   	printf("%s %s\n",s1[i],s2[i]);
   }
   printf("%s %s",s1[i],s2[i]);
   }
	return 0;
}
