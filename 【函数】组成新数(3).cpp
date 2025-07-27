#include <stdio.h>
int fun(int a,int b)
{
	int a1,a2,a3,a4,y;
	a1=a/10;
	a2=a%10;
	a3=b/10;
	a4=b%10;
	y=a4*1000+a1*100+a3*10+a2;
	return y;
}
int main ()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0&&b==0)
		break;
		else
		{
			printf("%d\n",fun(a,b));
		}
	}
	return 0;
}
