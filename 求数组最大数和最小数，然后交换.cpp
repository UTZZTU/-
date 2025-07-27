#include <stdio.h>
#define n 10
int main ()
{
	int a[n],*p,i,min=9999999,max=-9999999,num1,num2,t;
	p=a;
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		if(p[i]>max)
		{
			max=p[i];
			num2=i;
		}
		if(p[i]<min)
		{
			min=p[i];
			num1=i;
		}
	}
	if(num1==9&&num2==0)
	{
		t=p[num2];
		p[num2]=p[num1];
		p[num1]=t;
	}
	else
	{
		t=p[num1];
		p[num1]=p[0];
		p[0]=t;
		t=p[num2];
		p[num2]=p[9];
		p[9]=t;
	}
	for(i=0;i<n-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d",a[n-1]);
	return 0;
}
