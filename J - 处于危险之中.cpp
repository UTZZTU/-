#include <stdio.h>
#include <math.h>
int w[100000000];
int main ()
{
	int s,i,a,b,c,t;
	char q[4];
	w[0]=0;
	s=0;
	for(i=2;i<100000000;i++)
    {
    	s=(s+2)%i;
    	w[i-1]=s;
	}
    while(gets(q)!=NULL)
    {
    a=q[0]-'0';
    b=q[1]-'0';
    c=q[3]-'0';
    if(a==0&&b==0&&c==0)
    break;
    else
    {
    	t=(a*10+b)*pow(10,c);
    	if(t==1)
    	printf("0\n");
    	else
	printf("%d\n",w[t-1]+1);
	}
	}
	return 0;
 } 
