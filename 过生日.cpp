#include <stdio.h>
int main ()
{
	int a[13],t,n,y,r,d,i,j;
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
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&n,&y,&r);
		d=0;
		if(n%4==0&&n%100!=0||n%400==0)
		a[2]=29;
		else
		a[2]=28;
		d+=a[y]-r;
		for(j=y+1;j<9;j++)
		{
			d+=a[j];
		}
		d+=1;
	    printf("%d",d);
	    if(i!=t)
	    printf("\n");
	}
	return 0;
}