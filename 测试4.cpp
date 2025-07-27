#include <stdio.h>
int main ()
{
	int s;
	
				for(long int i=1;i<=99;i++)
				{
					if(i%2==0||i%3==0||i%5==0)
					{
						s=i;	
						if(s>7)
					printf("%d",s);
					break;
					}
					
				}
				
		
	return 0;
}
