#include <stdio.h>
int a(int w)
{
	int m=2,sum=0;
scanf("%d",&w);
while(1)	
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
	   return 1;

	
}
	
} 
int main ()
{
	int T,s=1;
	scanf("%d",&T);
	while(s<=T)
	{
		int q;
		scanf("%d",&q);
		if(a(q)==1)
		{
			printf("yes\n");
		}else if (a(q)!=1)
		printf("no\n");
		s++;
	}return 0;
}
