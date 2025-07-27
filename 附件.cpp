#include <stdio.h>
int main ()
{
	int m=2,sum=0,w,s=1;
scanf("%d",&w);
while(m<=999)	
{

	for(int i=1;i<m;i++)
	{
		if(m%i==0)
		{
			sum+=i;
			
		}
		
	}
	
	m++;
	if(w==sum)
	printf("yes\n");
	else s++;
}if(s>=m-1)
printf("no\n");

return 0;
}
