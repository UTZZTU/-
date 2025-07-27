#include <stdio.h>
int fun(int *a,int *b)
{
   int c;
   c=*a;
   *a=*b;
   *b=c;
}
int main ()
{
    int a,b,*p1,*p2;
    scanf("%d %d",&a,&b);
    p1=&a;
   p2=&b;
    fun(p1,p2);
    printf("%d %d",a,b);
	return 0;
}
