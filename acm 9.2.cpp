#include <stdio.h>
int main ()
{
    int n,a,min,w,sum;
    scanf("%d",&n);
    while(n--)
    {
    	min=1000000000;
    	scanf("%d",&a);
    	int c[10];
    	for(int i=0;i<a;i++)
    	{
    		scanf("%d",&c[i]);
    		if(c[i]<min)
    		min=c[i];
		}
		for(int i=1;i<=min;i++)
		{
			w=0;
			for(int b=0;b<a;b++)
			{
				if(c[b]%i!=0)
				break;
				else  w++;
			}
			if(w==a)
			sum=i;
		}
		printf("%d\n",sum);	
	}
	return 0;
}
