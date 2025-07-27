#include <stdio.h>
int main ()
{
	int a,b,c,d,sum;
	double s;
	while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
	{
		sum=0;
		if(a==0&&b==0&&c==0&&d==0)
		break;
		else
		{
			sum=sum+80;
			if(a<b)
			{
				sum=sum+a+40-b;
			}
			else {
				sum=sum+a-b;
			}
			sum=sum+40;
			if(b>=c)
			{
				sum=sum+40-b+c;
			}
			else 
			{
				sum=sum+c-b;
			}
			if(c<=d)
			{
				sum=sum+c+40-d;
			}
			else
			{
				sum=sum+c-d;
			}
			s=sum*1.0/40*360;
			printf("%.0f\n",s);
		}
	}
	return 0;
}
