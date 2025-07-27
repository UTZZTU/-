#include <stdio.h>
double fun(int n)
{
	double s=0;
	for(int i=1;i<=n;i++)
	{
		s+=1.0/(i*(i+1));
	}
	return s;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			printf("%.6f\n",fun(n));
		 } 
	}
	return 0;
}
