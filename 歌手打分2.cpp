#include <stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	int sum=0,s=100; 
	for (int i=0;i<n;i++)
		{
			
			int c[i];
			scanf("%d",&c[i]);
			
       
        	
        	if(s>c[i])
        	s=c[i];
		
			sum+=c[i];
		}
		printf("%d",sum-s);
		return 0;
	}
