#include <stdio.h>
#include <math.h>
int main ()
{
  int n,s,t,m,q;
 while(scanf("%d%d%d",&n,&s,&t)!=EOF)
 {
 	q=0;
     int c[100],b[100];
 	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&c[i]);
 		if(i>=s-1&&i<=t-1)
 		{
 			b[q]=c[i];
 			q++;
		 }
	 }
	for(int i=0;i<t-s;i++)
	{
		for(int a=0;a<t-s-i;a++)
		{
			if(b[a]<b[a+1])
			{
				m=b[a];
				b[a]=b[a+1];
				b[a+1]=m;
			}
		}
	}
		for(int i=0;i<s-1;i++)
	 {
	 	printf("%d ",c[i]);
	 }
	if(t==n)
	{
		for(int i=0;i<t-s;i++)
	{
		printf("%d ",b[i]);
	}
		printf("%d",b[t-s]);
		printf("\n");
	}
	else if(t!=n)
	{
		for(int i=0;i<t-s+1;i++)
	{
		printf("%d ",b[i]);
	}
for(int i=t;i<n-1;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[n-1]);
		printf("\n");
	}
 }
return 0;
}
