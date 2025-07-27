#include <stdio.h>
#include <math.h>
int main ()
{
   int m,n,w;
   while (scanf("%d%d",&m,&n)!=EOF)
   {
   	w=2;
   	if(m>=n)
   	{
   		for (int i=2;i<=n;i++)
   		{
   			if(m%i==0&&n%i==0)
   			break;
   			else 
   			w++;
		   }
		   if(w==n+1)
		   printf("Yes\n");
		   else printf("No\n");
	   }
	   else
	   {
	   	for (int i=2;i<=m;i++)
   		{
   			if(m%i==0&&n%i==0)
   			break;
   			else 
   			w++;
		   }
		   if(w==m+1)
		   printf("Yes\n");
		   else printf("No\n");
	   }
   }
	return 0;
}
