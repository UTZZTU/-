#include <stdio.h>
int main ()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
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
		int g=2;
		for(int e=2;e<n;e++)
		{
			if(n%e!=0)
		    g++;
		}
		if(n==g||n==1)
		{
			printf("No\n");
		}
		else
		{
		for (int d=0;d<=99;d++)
		{
		
			 if(n%c[d]==0)
			{
			   printf("%d",c[d]);	
				while(1)
				{
					
					n=n/c[d];
				if(n==1)
				{
					break;
				}
					else if(n%c[d]!=0)
						{
							printf(" ");
						break;
					}
			
				}
			
			}
		
		 } 
		printf("\n");
	}
	}
	return 0;
}
