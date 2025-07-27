#include "stdio.h"
int main()
{
int a,b,c,d,e,L;
int flag = 0;
for (L=1;L<=1000;L++)
{
for (a=1;a<=L;a++)
{
b=L-2*a;
c=L-3*b;
d=L-4*c;
e=L-5*d;
if (6*e+a == L)
{
flag = 1;
break;
}
}
if (flag) break;
}
if (flag) 
{
	printf("%d\n",L);
	printf("%d %d %d %d %d",a,b,c,d,e);
}
return 0;
}
