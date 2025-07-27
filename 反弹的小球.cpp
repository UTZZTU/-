#include <stdio.h>
int main ()
{
	int h,n,i;
	double s,sum=0;
	scanf("%d%d",&h,&n);
	s=h;
	if(n==1)
	printf("%.2f",s);
	else
	{
		sum+=s;
		for(i=1;i<n;i++)
		{
			s*=2.0/3;
			sum+=2*s;
		}
		printf("%.2f",sum);
	}
	return 0;
}