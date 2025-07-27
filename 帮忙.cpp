#include <stdio.h>
int main ()
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
		
	return 0;
}
