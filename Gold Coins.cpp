#include <stdio.h>
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
		int w=n,sum=0;
		for(int i=1;i<=10000;i++)
		{
			w=w-i;
		if(w>0)
		{
			sum+=i*i;
		}
		else if(w<=0)
			{
				w=w+i;
				sum=sum+w*i;
				break;
			}
			
		}
		printf("%d %d\n",n,sum);
	}
}
	return 0;
}
