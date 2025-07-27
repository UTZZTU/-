#include<stdio.h>
int main ()
{
	int x,y,i,j,n;
	double s,r;
	scanf("%d%d",&x,&y);
	r=1000*1.0/y*x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		s=1000*1.0/y*x;
		if(s<r)
		r=s;
	}
	printf("%.2f",r);
	return 0;
 } 
