#include <stdio.h>
int fun(int a,int b)
{
	int t;
	if(a<=b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main ()
{
	int fz1,fz2,fm1,fm2,fz3,fz4,min,max,fz,fm;
	char s;
	scanf("%d/%d%c%d/%d",&fz1,&fm1,&s,&fz2,&fm2);
	if(s=='+')
	{
		min=fun(fm1,fm2);
		max=fm1/min*fm2;
		fz3=fz1*(max/fm1);
		fz4=fz2*(max/fm2);
		fz=fz3+fz4;
		fm=max;
		min=fun(fz,fm);
		fz/=min;
		fm/=min;
		if(fz%fm==0)
		{
			printf("%d/%d+%d/%d=%d",fz1,fm1,fz2,fm2,fz/fm);
		}
		else
		{
			printf("%d/%d+%d/%d=%d/%d",fz1,fm1,fz2,fm2,fz,fm);
		}
	}
	else if(s=='-')
	{
		min=fun(fm1,fm2);
		max=fm1/min*fm2;
		fz3=fz1*(max/fm1);
		fz4=fz2*(max/fm2);
		fz=fz3-fz4;
		fm=max;
		min=fun(fz,fm);
		fz/=min;
		fm/=min;
		if(fz%fm==0)
		{
			printf("%d/%d-%d/%d=%d",fz1,fm1,fz2,fm2,fz/fm);
		}
		else
		{
			printf("%d/%d-%d/%d=%d/%d",fz1,fm1,fz2,fm2,fz,fm);
		}
	}
	else if(s=='*')
	{
		fz=fz1*fz2;
		fm=fm1*fm2;
		min=fun(fz,fm);
		fz/=min;
		fm/=min;
		if(fz%fm==0)
		{
			printf("%d/%d*%d/%d=%d",fz1,fm1,fz2,fm2,fz/fm);
		}
		else
		{
			printf("%d/%d*%d/%d=%d/%d",fz1,fm1,fz2,fm2,fz,fm);
		}
	}
	else if(s=='/')
	{
		fz=fz1*fm2;
		fm=fm1*fz2;
		min=fun(fz,fm);
		fz/=min;
		fm/=min;
		if(fz%fm==0)
		{
			printf("%d/%d/%d/%d=%d",fz1,fm1,fz2,fm2,fz/fm);
		}
		else
		{
			printf("%d/%d/%d/%d=%d/%d",fz1,fm1,fz2,fm2,fz,fm);
		}
	}
	return 0;
}
