#include <stdio.h>
#include <math.h>
int main ()
{
	int a,b,s;
	scanf("%d %d",&a,&b);
	s=a;
	for(int i=1;i<=b-1;i++)
	{
		a*=s;
		a=a%7;
	}
	if(a%7==0)
	printf("Sunday");
	else if(a%7==1)
	printf("Monday");
	else if(a%7==2)
	printf("Tuesday");
	else if(a%7==3)
	printf("Wednesday");
	else if(a%7==4)
	printf("Thursday");
	else if(a%7==5)
	printf("Friday");
	else if(a%7==6)
	printf("Saturday");
	return 0;
}
