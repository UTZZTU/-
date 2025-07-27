#include <stdio.h>
int main ()
{
	int w,T;
	scanf("%d",&T);
		for(int i=1;i<=T;i++)
		{
			int m=2,s=1;
            scanf("%d",&w);
             while(m<=999)	
           {
             int sum=0;
	    for(int i=1;i<m;i++)
	     {
	    	if(m%i==0)
			sum+=i;
	     }
	         m++;
	         if(w==sum)
	         {
			 printf("no\n");
			 break;
		}
	          else s++;
           }
		   if(s>=m-1)
           printf("yes\n");
       }
    
           return 0;
}
