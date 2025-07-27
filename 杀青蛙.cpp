#include <stdio.h>
int main ()
{
	int n,k,m,s;
	scanf("%d %d %d",&n,&k,&m);
	if(m%k==0)
	{
		s=n-m/k;
		if(s<0)
		{
			s=0;
		}
	}
	else 
	{
		s=n-m/k-1;
		if(s<0)
		{
			s=0;
		}
	}
	printf("%d",s);
	return 0;
}
