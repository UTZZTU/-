#include <stdio.h>
int main ()
{
	int a,b,i,sum,k,max=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		k=i;
		sum=1;
		while(k!=1)
		{
			if(k%2==0)
			k/=2;
			else 
			{
				k=3*k+1;
			}
			sum++;
		}
		if(sum>max)
		max=sum;
	}
	printf("%d",max);
	return 0;
}