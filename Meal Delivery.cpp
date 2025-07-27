#include <stdio.h>
int main ()
{
	int x,a,b,s1,s2;
	scanf("%d%d%d",&x,&a,&b);
	s1=x-a;
	s2=x-b;
	if(s1<0)
	s1*=-1;
	if(s2<0)
	s2*=-1;
	if(s1<s2)
	printf("A");
	else
	printf("B");
	return 0;
}