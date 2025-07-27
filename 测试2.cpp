#include <stdio.h>
int a(int w)
{
	int m=2,s=0;
scanf("%d",&w);
while(m<=999)	
{
	
int sum=0;
	for(int i=1;i<m;i++)
	{
		if(m%i==0)
		{
			sum+=i;
			
		}	
	} 
	
	
       if(w==sum)
	   return 1;
	   else s++;
	   m++;

	
}
if(s>=998)
return 2;
}
int main ()
{
	int q;
	if(a(q)==1)
	printf("yes");
	else if (a(q)==2)
	printf("no");
	return 0;
}
