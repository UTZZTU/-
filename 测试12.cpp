#include <stdio.h>
int main ()
{     
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
	int sum=0;
int x1,y1,x2,y2,t=0;
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
for(int a=1;a<=100000000;a++)
{	
for(int b=1;b<=100000000;b++)
{
	if(x1==x2&&y1==y2)
	{
		t++;
		break;
	}
	sum++;
	if(y1==0)
	break;
	y1=y1-1;
	x1=x1+1;
}
if(t==1)
break;
y1=x1+1;
x1=0;
}
printf("Case %d: %d\n",i,sum);
}
		return 0;
}
