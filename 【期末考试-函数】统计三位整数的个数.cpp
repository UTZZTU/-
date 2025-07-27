#include <stdio.h>
#include <string.h> 
int fun(int n)
{   
   long long int s=1;
   for(int i=1;i<=n;i++)
   {
   	s*=i;
   }
   return s;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		double s=0,t;
		for(int i=1;i<=n;i++)
		{
			t=1.0/fun(2*i+1);
			s+=t;
		}
		printf("%.6f\n",s);
	}
	return 0;
}
