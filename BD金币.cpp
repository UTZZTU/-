#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n); 
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
printf("%d",sum);
	return 0;
}
