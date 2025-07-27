#include <stdio.h>
int main ()
{
	long long int i,j,sum,w;
	while(scanf("%d %d",&i,&j)!=EOF)
	{
		int s=0;
		if(i>j)
		{
			for(int a=j;a<=i;a++)
			{
				sum=0;
				w=a;
			for(int b=1;b<=10000;b++)
				{
				    sum++;
					if(w==1)
				    break;
					else 
					{
					if(w%2==0)
						w=w/2;
					else 
					{
						w=(3*w+1)/2;
						sum++;
					}
						
					}
				}
				if(sum>s)
				s=sum;
			}
			printf("%d %d %d\n",i,j,s);
		}
		else if(i<=j)
		{
			for(int a=i;a<=j;a++)
			{
				sum=0;
				w=a;
				for(int b=1;b<=10000;b++)
				{
					sum++;
					if(w==1)
			    {
					break;
				}
				else
				{
					 if(w%2==0)
						w=w/2;
					 else 
					 {
					 	w=(3*w+1)/2;
					 	sum++;
					 }
						
                }
				}
				if(sum>s)
				s=sum;
			}
			printf("%d %d %d\n",i,j,s);
		} 
		
	}
	return 0;
}
