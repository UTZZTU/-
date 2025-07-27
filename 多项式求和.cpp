#include <stdio.h>
int main ()
{
	int m,a=1;
	scanf("%d",&m);
	while(a<=m)
	{
		double sum=0;
		int n;
		int s=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			s++;
			if(i%2!=0)
			{
				sum+=1.0/s;
			}
			else 
			{
				sum-=1.0/s;
			}
			
		}
		a++;
		printf("%.2f\n",sum);
	}
	return 0;
}
