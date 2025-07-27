#include <stdio.h>
void change(int n,int *p,int *q)
{
	int s=0,w=0,sum=1;
	while(n!=0)
	{
		if(sum%2==1)
		{
			s+=n%10;
		}
		else
		{
			w+=n%10;
		}
		n/=10;
		sum++;
	}
	*p=s;
	*q=w;
}
int main ()
{
   int n,j,o,*p,*q;
   scanf("%d",&n);
   p=&j;
   q=&o;
   change(n,p,q);
   printf("%d %d",j,o);
    return 0;
}
