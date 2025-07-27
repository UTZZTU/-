#include <stdio.h>
int main ()
{
	int n,x,i,k,t,sum=0;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{
		k=i;
		while(k!=0)
		{
			t=k%10;
			if(t==x)
			sum++;
			k/=10;
		}
	}
	printf("%d",sum);
	return 0;
}