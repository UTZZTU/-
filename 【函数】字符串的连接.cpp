#include <stdio.h>
void fun()
{
    char s[100],t[100];
	gets(s);
	gets(t);
	printf("%s%s",&s,&t);
 } 
 int main ()
 {
 	int t;
 	char w;
 	scanf("%d",&t);
 	w=getchar();
 	for(int i=1;i<=t;i++)
 	{
 		fun();
 		if(i!=t)
 		printf("\n");
	 }
	 return 0;
 }
