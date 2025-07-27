#include <stdio.h>
#include <math.h>
int main ()
{
	int n,w=2,s=0,min,q;
	double t;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(n%(i*i)==0)
		{
			printf("0");
			break;
		}
		else w++;
	}
	if(w==n+1)
	{
		for(int a=2;a<=n;a++)
		{
			q=0;
			t=sqrt(a);
			for(int b=1;b<=t;b++)
			{
				if(a%b==0)
				q++;
			}
			if(q==1)
			{
				if(n%a==0)
				s++;
			} 
		}
		min=pow(-1,s);
		printf("%d",min);
	}
	return 0;
}
