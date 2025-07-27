#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
double n;
int main ()
{
	scanf("%lf",&n);
	for(int i=0;i<5;i++)
	{
		printf("%c: ",'A'+i);
		if(i==0)
		{
			printf("%.2lf %.2lf",(double)sin(18.0*PI/180)*n+n,(double)0);
		}
		else if(i==1)
		{
			printf("%.2lf %.2lf",(double)n*sin(54.0*PI/180),-(((double)sin(18.0*PI/180)*n*2+2*n)*cos(18.0*PI/180)-(double)n*cos(18.0*PI/180)));
		}
		else if(i==2)
		{
			printf("%.2lf %.2lf",-(double)n*sin(54.0*PI/180),-(((double)sin(18.0*PI/180)*n*2+2*n)*cos(18.0*PI/180)-(double)n*cos(18.0*PI/180)));
		}
		else if(i==3)
		{
			printf("%.2lf %.2lf",-(double)sin(18.0*PI/180)*n-n,(double)0);
		}
		else
		{
			printf("%.2lf %.2lf",(double)0,(double)n*cos(18.0*PI/180));
		}
		printf("\n");
	}
	return 0;
}