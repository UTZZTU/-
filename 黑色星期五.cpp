#include <stdio.h>
int main ()
{
	int a[13],n,xq,i,d;
	a[1]=31;
	a[3]=31;
	a[4]=30;
	a[5]=31;
	a[6]=30;
	a[7]=31;
	a[8]=31;
	a[9]=30;
	a[10]=31;
	a[11]=30;
	a[12]=31;
	scanf("%d%d",&n,&xq);
	if(n%4==0&&n%100!=0||n%400==0)
	a[2]=29;
	else
	a[2]=28;
	d=1;
	for(i=1;i<=12;i++)
	{
		xq+=13-d;
		d=13;
		xq%=7;
		if(xq==5)
		printf("%d/%d/13\n",n,i);
		xq+=a[i]-d;
		d=0;
		xq%=7;
	}
	return 0;
}