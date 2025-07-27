#include <stdio.h>
int main ()
{
	int c[100];
	int n,w,sum,s;
	while (scanf("%d",&n)!=EOF)
	{
	     
		sum=0;
		w=0;
		s=100;
		double tm;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]>w)
			w=c[i];
        	if(c[i]<s)
        	s=c[i];
			sum+=c[i];
		}
		tm=(sum-w-s)*1.0/(n-2);
		printf("%.2f\n",tm);
	} 
	return 0; 
}
