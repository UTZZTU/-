#include <stdio.h>
int main ()	
{
int a,b,result;
char i;
scanf("%d %d %c",&a,&b,&i);
if(i=='+')
{
	result=a+b;
	printf("%d",result);
}else if(i=='-')
{
	result=a-b;
	printf("%d",result);
}else if(i=='*')
{
	result=a*b;
	printf("%d",result);
}else if(i=='/')
{
	result=a/b;
	printf("%d",result);
}
	return 0;
	}


