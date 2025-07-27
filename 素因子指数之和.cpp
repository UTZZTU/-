#include <stdio.h>
int main ()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
			int s,sum=0;
		int c[99];
	c[0]=2;
	int a=3;
		for(int i=1;i<=99;i++)
		{
		   while(a<=999)
		   {
		    int w=2;
		   	for(int b=2;b<a;b++)
		   	{
		   		if(a%b==0)
		   		break;
		   		else  w++;
			   }
			   
			   if(w==a)
			   {
			   c[i]=a;
			   a++;
			   break;
	           }
	           else a++;
		   }
		}
		for (int d=0;d<=99;d++)
		{
			int g=0;
			if(n%c[d]==0)
			{
				while(1)
				{
					n=n/c[d];
					g++;
					if(n%c[d]!=0)
						{
						break;
					}
			
				}
				
			}
			sum+=g;
		 } 
		 printf("%d\n",sum);
	}
	return 0;
}
