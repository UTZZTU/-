#include <stdio.h>
int main ()
{
	int a,b,c,d;
	while(scanf("%d/%d/%d",&a,&b,&c)!=EOF)
	{
		if(a%4==0&&a%100!=0||a%400==0)
		{
			if(b==1)
			{
				d=c;
				printf("%d\n",d);
			}
			else if(b==2)
			{
				d=c+31;
				printf("%d\n",d);
			}
			else if(b==3)
			{
				d=c+31+29;
				printf("%d\n",d);
			}
			else if(b==4)
			{
				d=c+31+29+31;
				printf("%d\n",d);
			}
			else if(b==5)
			{
				d=c+31+29+31+30;
				printf("%d\n",d);
			}
			else if(b==6)
			{
				d=c+31+29+31+30+31;
				printf("%d\n",d);
			}
			else if(b==7)
			{
				d=c+31+29+31+30+31+30;
				printf("%d\n",d);
			}
			else if(b==8)
			{
				d=c+31+29+31+30+31+30+31;
				printf("%d\n",d);
			}
			else if(b==9)
			{
				d=c+31+29+31+30+31+30+31+31;
				printf("%d\n",d);
			}
			else if(b==10)
			{
				d=c+31+29+31+30+31+30+31+31+30;
				printf("%d\n",d);
			}
			else if(b==11)
			{
				d=c+31+29+31+30+31+30+31+31+30+31;
				printf("%d\n",d);
			}
			else if(b==12)
			{
				d=c+31+29+31+30+31+30+31+31+30+31+30;
				printf("%d\n",d);
			}
		}
		else 
		{
			if(b==1)
			{
				d=c;
				printf("%d\n",d);
			}
			else if(b==2)
			{
				d=c+31;
				printf("%d\n",d);
			}
			else if(b==3)
			{
				d=c+31+28;
				printf("%d\n",d);
			}
			else if(b==4)
			{
				d=c+31+28+31;
				printf("%d\n",d);
			}
			else if(b==5)
			{
				d=c+31+28+31+30;
				printf("%d\n",d);
			}
			else if(b==6)
			{
				d=c+31+28+31+30+31;
				printf("%d\n",d);
			}
			else if(b==7)
			{
				d=c+31+28+31+30+31+30;
				printf("%d\n",d);
			}
			else if(b==8)
			{
				d=c+31+28+31+30+31+30+31;
				printf("%d\n",d);
			}
			else if(b==9)
			{
				d=c+31+28+31+30+31+30+31+31;
				printf("%d\n",d);
			}
			else if(b==10)
			{
				d=c+31+28+31+30+31+30+31+31+30;
				printf("%d\n",d);
			}
			else if(b==11)
			{
				d=c+31+28+31+30+31+30+31+31+30+31;
				printf("%d\n",d);
			}
			else if(b==12)
			{
				d=c+31+28+31+30+31+30+31+31+30+31+30;
				printf("%d\n",d);
			}
		}
	}
	return 0;
}
